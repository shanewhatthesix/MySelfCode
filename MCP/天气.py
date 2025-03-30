import requests
from functools import lru_cache

weather_url = 'http://t.weather.sojson.com/api/weather/city/'
session = requests.Session()

@lru_cache(maxsize=32)
def get_weather(city_code="101240101"):
    """获取天气信息(带5分钟缓存)"""
    try:
        response = session.get(
            weather_url + city_code,
            timeout=(5, 10)  # 连接5秒，读取10秒
        )
        data = response.json()

        if data.get('status') != 200:
            return "天气数据获取失败。"

        city_info = data.get('cityInfo', {})
        forecast = data.get('data', {}).get('forecast', [{}])[0]
        
        return (
            f"城市: {city_info.get('parent', '')} {city_info.get('city', '')}\n"
            f"日期: {data.get('time', '')} {forecast.get('week', '')}\n"
            f"温度: {forecast.get('high', '')}~{forecast.get('low', '')}\n"
            f"天气: {forecast.get('type', '')}"
        )
    except Exception as e:
        return f"获取天气信息时出错: {str(e)}"

if __name__ == "__main__":
    weather_info = get_weather()
    print(weather_info)
