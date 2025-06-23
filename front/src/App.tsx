import { Keypad } from './components/keypad/Keypad'
import './App.css'

function App() {

  return (
    <div className='App'>
      <div className='keypad-display-container'>
        <p className='keypad-display' />
      </div>
      <Keypad
        onNumberClick={(number) => {
          const element = document.querySelector('.keypad-display');
          if (element) {
            element.textContent += number.toString();
          }
        }}
      />
    </div>
  )
}

export default App
