let change = false;

setImage();
timeTableBtn();

// 요구조건 1번: [ 속성 변경 ]
function setImage(){
    const img = document.querySelector('#mainPageImage')
    img.addEventListener("click", ()=>{
        if(change){
            img.setAttribute("src", "img/cafe1.png");
            change = false;
        }else{
            img.setAttribute("src", "img/cafe2.png");
            change = true;
        }
    })
}


//[3] 마우스 입력 방식 추가 스타일 변경
function timeTableBtn(){
    const tag = document.querySelector('#timeTableBtn')
    tag.addEventListener('mouseover', () => {
        showTimeTableTag();
        tag.setAttribute("style","background-color: #843; color: #fff");
        console.log("over");
      });
      
    tag.addEventListener('mouseout', () => {
        hideTimeTableTag();
        tag.setAttribute("style","background-color: #fff; color: #000 ");
        console.log("out");
    });
}

// content변경
function hideTimeTableTag(){
    const target = document.querySelector('#timeTables');
    target.textContent = "";
    
}

function showTimeTableTag(){
    const target = document.querySelector('#timeTables');
    target.innerHTML = timeTableTag();
}


function timeTableTag(){
    return `
    <table id ="priceTable">
        <caption>가격표</caption>
        <col style="width: 15%; background-color: antiquewhite;">
        <col class="roomCol" style="width: 20%;">
        <col class="roomCol" style="width: 20%;">
        <col class="roomCol" style="width: 20%;">
        <col class="roomCol" style="width: 20%;">
        <thead>
        <tr>
            <th>시간</th>
            <th>1호실</th>
            <th>2호실</th>
            <th>3호실</th>
            <th>4호실</th>
        </tr>
        </thead>
        <tbody>
        <tr>
            <td>1시간</td>
            <td>10000원</td>
            <td>12000원</td>
            <td>20000원</td>
            <td>40000원</td>
        </tr>
        <tr>
            <td>2시간</td>
            <td>20000원</td>
            <td>30000원</td>
            <td>40000원</td>
            <td>50000원</td>
        </tr>
        <tr>
            <td>3시간</td>
            <td>40000원</td>
            <td>60000원</td>
            <td>70000원</td>
            <td>80000원</td>
        </tr>
        </tbody>
    </table>`
}