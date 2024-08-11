/*

[1] 문서객체의 constents, 속성, 스타일 변경 기능 - 3가지 모두 사용 / 최소 3가지 이상의 문서객체에 적용 [V]

[2] 문서 객체 생성 또는 이동, 제거기능 - 2가지 모두 사용 / 최소 1가지 문서 객체에 적용 [V]

[3] 다양한 입력방식에 이벤트 활용 - 최소 4가지 이상 다른 종류의 입력양식에 적용 [V]

[4] 키보드 / 마우스 이벤트 - 모두 적용 [V]

*/




document.addEventListener('DOMContentLoaded',()=>{
    addSNS();
})

// 요구조건 1번: [ 속성 변경 ]
// 요구조건2 : [ 생성및 이동 ]
function addSNS(){
    const side = document.querySelector('#snsBox');
    const SNSProvider = ['트위터', '페이스북'];

    for(var i=0; i < SNSProvider.length; i++){
        const SNSitem = document.createElement('img');
        SNSitem.style.height = '80px';
        SNSitem.style.marginBottom = '10px';
        SNSitem.setAttribute("src",`img/${SNSProvider[i]} 아이콘.png`);
        side.appendChild(SNSitem);
    }
}



