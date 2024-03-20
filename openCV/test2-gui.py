import sys
from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QVBoxLayout
from PyQt5.QtGui import QIcon
from PyQt5.QtCore import Qt

class MyGUI(QWidget):
    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        # 버튼 생성
        self.button = QPushButton('클릭하세요', self)

        # 레이아웃 생성
        layout = QVBoxLayout()
        layout.addWidget(self.button)

        # 위젯에 레이아웃 설정
        self.setLayout(layout)

        # 윈도우 크기 및 제목 설정
        self.setGeometry(200, 100, 600, 400)  # 위치 (200, 100), 크기 600x400으로 변경
        self.setWindowTitle('Dark Mode PyQt 예제')

        # 윈도우 바 숨기기
        self.setWindowFlags(self.windowFlags() | Qt.FramelessWindowHint)

        # todo : 커스텀 상단바 생성하기

        # 스타일 시트 적용
        self.setStyleSheet("""
            QWidget {
                background-color: #272822;
                color: #f8f8f2;
                font-family: Arial, sans-serif;
            }
            QPushButton {
                background-color: #6272a4;
                color: #f8f8f2;
                border-radius: 5px;
                padding: 10px;
            }
            QPushButton:hover {
                background-color: #818eae;
            }
        """)

        self.show()

if __name__ == '__main__':
    app = QApplication(sys.argv)
    app.setWindowIcon(QIcon("icon.png"))  # 아이콘 설정 (필요시)
    my_gui = MyGUI()
    sys.exit(app.exec_())