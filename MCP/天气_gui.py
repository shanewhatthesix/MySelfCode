import sys
from PyQt5.QtWidgets import (QApplication, QMainWindow, QWidget, QVBoxLayout, 
                            QLabel, QComboBox, QPushButton, QTextEdit, QHBoxLayout)
from PyQt5.QtCore import Qt, QSize
from PyQt5.QtGui import QFont, QIcon, QPalette, QColor
from 天气 import get_weather

class WeatherApp(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("天气预报")
        self.setFixedSize(450, 550)
        self.dark_mode = False
        
        # 城市代码映射
        self.city_codes = {
            "南昌": "101240101",
            "北京": "101010100", 
            "上海": "101020100",
            "广州": "101280101",
            "深圳": "101280601"
        }
        
        self.init_ui()
        self.set_light_theme()
        
    def init_ui(self):
        central_widget = QWidget()
        self.setCentralWidget(central_widget)
        main_layout = QVBoxLayout(central_widget)
        main_layout.setContentsMargins(20, 20, 20, 20)
        main_layout.setSpacing(15)
        
        # 标题栏
        title_layout = QHBoxLayout()
        self.title_label = QLabel("天气预报")
        self.title_label.setAlignment(Qt.AlignCenter)
        
        # 主题切换按钮
        self.theme_btn = QPushButton()
        self.theme_btn.setFixedSize(30, 30)
        self.theme_btn.setIcon(QIcon.fromTheme("color-scheme"))
        self.theme_btn.clicked.connect(self.toggle_theme)
        
        title_layout.addWidget(self.title_label)
        title_layout.addWidget(self.theme_btn)
        main_layout.addLayout(title_layout)
        
        # 城市选择
        self.city_combo = QComboBox()
        self.city_combo.addItems(self.city_codes.keys())
        main_layout.addWidget(self.city_combo)
        
        # 操作按钮布局
        btn_layout = QHBoxLayout()
        self.query_btn = QPushButton("查询天气")
        self.query_btn.clicked.connect(self.query_weather)
        
        self.copy_btn = QPushButton("复制结果")
        self.copy_btn.clicked.connect(self.copy_to_clipboard)
        
        btn_layout.addWidget(self.query_btn)
        btn_layout.addWidget(self.copy_btn)
        main_layout.addLayout(btn_layout)
        
        # 天气信息显示
        self.weather_display = QTextEdit()
        self.weather_display.setReadOnly(True)
        main_layout.addWidget(self.weather_display)
        
        # 设置字体
        self.set_fonts()
        
    def set_fonts(self):
        font = QFont()
        font.setFamily("Microsoft YaHei")
        
        title_font = QFont(font)
        title_font.setPointSize(18)
        title_font.setBold(True)
        self.title_label.setFont(title_font)
        
        content_font = QFont(font)
        content_font.setPointSize(12)
        self.city_combo.setFont(content_font)
        self.query_btn.setFont(content_font)
        self.copy_btn.setFont(content_font)
        self.weather_display.setFont(content_font)
        
    def set_light_theme(self):
        palette = self.palette()
        palette.setColor(QPalette.Window, QColor(240, 240, 240))
        palette.setColor(QPalette.WindowText, QColor(0, 0, 0))
        palette.setColor(QPalette.Base, QColor(255, 255, 255))
        palette.setColor(QPalette.Text, QColor(0, 0, 0))
        palette.setColor(QPalette.Button, QColor(53, 53, 53))
        palette.setColor(QPalette.ButtonText, QColor(255, 255, 255))
        self.setPalette(palette)
        
        self.dark_mode = False
        self.theme_btn.setIcon(QIcon.fromTheme("weather-clear-night"))
        
    def set_dark_theme(self):
        palette = self.palette()
        palette.setColor(QPalette.Window, QColor(53, 53, 53))
        palette.setColor(QPalette.WindowText, QColor(255, 255, 255))
        palette.setColor(QPalette.Base, QColor(25, 25, 25))
        palette.setColor(QPalette.Text, QColor(255, 255, 255))
        palette.setColor(QPalette.Button, QColor(53, 53, 53))
        palette.setColor(QPalette.ButtonText, QColor(255, 255, 255))
        self.setPalette(palette)
        
        self.dark_mode = True
        self.theme_btn.setIcon(QIcon.fromTheme("weather-clear"))
        
    def toggle_theme(self):
        if self.dark_mode:
            self.set_light_theme()
        else:
            self.set_dark_theme()
        
    def query_weather(self):
        city_name = self.city_combo.currentText()
        city_code = self.city_codes[city_name]
        weather_info = get_weather(city_code)
        self.weather_display.setText(weather_info)
        
    def copy_to_clipboard(self):
        clipboard = QApplication.clipboard()
        clipboard.setText(self.weather_display.toPlainText())

if __name__ == "__main__":
    app = QApplication(sys.argv)
    app.setStyle("Fusion")
    window = WeatherApp()
    window.show()
    sys.exit(app.exec_())
