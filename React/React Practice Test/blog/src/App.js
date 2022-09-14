import logo from './logo.svg';
import './App.css';

function App() {

  let cafe_name = '스타벅스';

  return (
    <div className="App">
      <div className='Head'> 카페 예약 </div>

        <div className='List'>
          <h3>{cafe_name}</h3>
          <p> 스타벅스입니다. </p>
          <hr/>
        </div>


    </div>
  );
}

export default App;
