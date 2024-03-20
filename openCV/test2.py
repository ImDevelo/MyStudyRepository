import sys
import cv2
from PyQt5.QtCore import QTimer
from PyQt5.QtGui import QImage, QPixmap
from PyQt5.QtWidgets import QApplication, QLabel, QWidget

class MainWindow(QWidget):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("Webcam")

        # 웹캠 캡처 객체 생성
        self.cap = cv2.VideoCapture(0)

        # 레이아웃 설정
        self.layout = QVBoxLayout()
        self.setLayout(self.layout)

        # 영상 표시 레이블
        self.label = QLabel()
        self.layout.addWidget(self.label)

        # 갱신 함수 설정
        self.timer = QTimer()
        self.timer.timeout.connect(self.update_frame)
        self.timer.start(100)

    def update_frame(self):
        ret, frame = self.cap.read()

        if ret:
            # 프레임을 RGB 형식으로 변환
            frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)

            # QImage 객체 생성
            image = QImage(frame.data, frame.shape[1], frame.shape[0], QImage.Format_RGB888)

            # QPixmap 객체 생성
            pixmap = QPixmap.fromImage(image)

            # 레이블에 표시
            self.label.setPixmap(pixmap)


if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec_())
    