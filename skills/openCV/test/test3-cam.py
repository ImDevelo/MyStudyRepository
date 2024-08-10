# Python GUI PyQt5 설치
#pip install PyQt5
# OpenCV 설치
#pip install opencv-python

# 필요한 모듈을 import합니다.
import sys
from PyQt5.QtWidgets import QApplication, QLabel, QMainWindow, QVBoxLayout, QWidget
from PyQt5.QtGui import QImage, QPixmap
from PyQt5.QtCore import QTimer
import cv2


# VideoStream 클래스를 정의합니다.
class VideoStream(QMainWindow):
    def __init__(self):
        super().__init__()

        # 윈도우의 제목과 크기를 설정합니다.
        self.setWindowTitle("Video Stream")
        self.setGeometry(100, 100, 800, 600)

        # 중앙 위젯을 생성합니다.
        self.central_widget = QWidget()
        self.setCentralWidget(self.central_widget)

        # 비디오를 표시할 QLabel 위젯을 생성합니다.
        self.video_label = QLabel()
        layout = QVBoxLayout()  # 수직 박스 레이아웃을 생성합니다.
        layout.addWidget(self.video_label)  # QLabel을 레이아웃에 추가합니다.
        self.central_widget.setLayout(layout)  # 중앙 위젯에 레이아웃을 설정합니다.

        # 웹캠으로부터 영상을 캡처하기 위한 VideoCapture 객체를 생성합니다.
        self.video_cap = cv2.VideoCapture(0)

        # QTimer를 사용하여 일정 시간 간격으로 프레임을 업데이트합니다.
        self.timer = QTimer(self)
        self.timer.timeout.connect(self.update_frame)  # 타이머가 만료될 때 update_frame 메서드를 호출합니다.
        self.timer.start(30)  # 30 밀리초마다 타이머를 시작합니다.

    # 프레임을 업데이트하는 메서드입니다.
    def update_frame(self):
        ret, frame = self.video_cap.read()  # 비디오 캡처 객체에서 프레임을 읽습니다.
        if ret:
            frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)  # BGR 형식을 RGB 형식으로 변환합니다.
            h, w, ch = frame.shape  # 프레임의 높이, 너비, 채널 수를 가져옵니다.
            bytes_per_line = ch * w  # 한 줄당 바이트 수를 계산합니다.
            # OpenCV 배열을 QImage 객체로 변환합니다.
            q_img = QImage(frame.data, w, h, bytes_per_line, QImage.Format_RGB888)
            pixmap = QPixmap.fromImage(q_img)  # QImage를 QPixmap으로 변환합니다.
            self.video_label.setPixmap(pixmap)  # QLabel에 QPixmap을 설정하여 영상을 표시합니다.

# 메인 실행 부분입니다.
if __name__ == "__main__":
    app = QApplication(sys.argv)  # QApplication 객체를 생성합니다.
    window = VideoStream()  # VideoStream 객체를 생성합니다.
    window.show()  # 윈도우를 표시합니다.
    sys.exit(app.exec_())  # 애플리케이션을 실행하고 이벤트 루프를 시작합니다.
