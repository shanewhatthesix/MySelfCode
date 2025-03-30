import requests

weather_url = 'http://t.weather.sojson.com/api/weather/city/'

def get_weather(city_code="101240101"):
    """获取天气信息"""
    try:
        response = requests.get(weather_url + city_code, timeout=10)
        data = response.json()

        if data['status'] != 200:
            return "天气数据获取失败。"

        area = f"{data['cityInfo']['parent']} {data['cityInfo']['city']}"
        today = f"{data['time']} {data['data']['forecast'][0]['week']}"
        temperature = f"{data['data']['forecast'][0]['high']}~{data['data']['forecast'][0]['low']}"
        weather = data['data']['forecast'][0]['type']

        return {
            "city": area,
            "date": today,
            "temperature": temperature,
            "weather": weather
        }
    except Exception as e:
        return {"error": f"获取天气信息时出错: {str(e)}"}

if __name__ == "__main__":
    import sys
    city_code = sys.argv[1] if len(sys.argv) > 1 else "101240101"
    result = get_weather(city_code)
    print(result)