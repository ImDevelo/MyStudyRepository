
document.addEventListener('DOMContentLoaded',()=>{
    setCalendar();
    setSubmit();
    setStartTime();
    setEndTime();
    selectRoom();
    colorColunm(1);
})



const ReserveFrom = {
    date: null,
    start: null,
    end: 1,
    room: 1,
}


// 요구 조건1 : [ 속성값 변경 ]
function setCalendar(){
    const cal = document.querySelector('[type="date"]')
    const date = new Date();
    const now_date = `${date.getFullYear()}-${date.getMonth() + 1}-${date.getDate()}`
    const max_date = `${date.getFullYear()}-${date.getMonth() + 2}-${date.getDate()}`
    
    cal.setAttribute("min",now_date);
    cal.setAttribute("max",max_date);

    cal.addEventListener("change", ()=>{
        ReserveFrom.date = cal.value;
    })
}

function setStartTime(){
    const time = document.querySelector('[type="time"]')
    time.addEventListener("change", ()=>{
        ReserveFrom.start = time.value;
    })
}

function setEndTime(){
    const time = document.querySelector('[type="number"]')
    time.addEventListener("change", ()=>{
        ReserveFrom.end = time.value
    })
}


function selectRoom(){
    const room = document.querySelector('#room')
    room.addEventListener("change", (event)=>{
        const options = event.currentTarget.options
        const index = event.currentTarget.options.selectedIndex;
        const num = options[index].value;
        ReserveFrom.room = num;
        colorColunm(num);
    })
}

/** 표 색 바꾸기 */
function colorColunm(value){
    const cols = document.querySelectorAll('.roomCol')
    for(var i=0; i<cols.length; i++){
        if(i==value-1){
            cols[i].setAttribute("style","background-color: #ffd;")
        }else{
            cols[i].setAttribute("style","background-color: #fff;")
        }
    }
}


// 요구조건 마우스
function setSubmit(){
    const btn = document.querySelector('[type="submit"]');
    btn.addEventListener("click",(event)=>{
        const r = ReserveFrom;
        if(r.date != null && r.start != null && r.end != null && r.room != null){
            console.log(r.date, r.start, r.end, r.room);
            alert("예약 되었습니다.");
            ShowReserve();
            event.preventDefault();
        }
    })
}

/** 예약시 예약내역 보여주기 */
function ShowReserve(){
    const target = document.querySelector('#reserveHistory');
    target.innerHTML =( 
        `<div id="reserveTable">
            <h3 style="margin:0"> 예약 내역 </h3>
            <div style="margin:10px"> 
            예약 날짜| ${ReserveFrom.date}  <br>
            예약 시간ㅣ${ReserveFrom.start} : ${ReserveFrom.end} 시간<br>  
            예약 호실| ${ReserveFrom.room} 호실
            </div>
            <button id="reserve"> 예약 </button> <button id="cancel" onclick="removeReserve()"> 취소 </button>
        </div>`);
}

/** 예약내역 삭제 */
//요구조건 : 삭제
function removeReserve(){
    const target = document.querySelector('#reserveHistory');
    target.removeChild(target.childNodes[0]);
    target.textContent = "예약내역이 없습니다."
}