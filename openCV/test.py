import cv2

# 비디오 캡처 객체 생성
cap = cv2.VideoCapture(0)

while True:
    # 프레임들 읽기
    ret, frame = cap.read()

    # 영상 처리 코드 작성
    # 예시: 영상을 회색으로 변환하기
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    # 영상 출력
    cv2.imshow('Real-time Video', gray)

    # 'q' 키를 누르면 종료
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# 객체 해제
cap.release()
cv2.destroyAllWindows()