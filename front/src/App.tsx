import { Keypad } from './components/keypad/Keypad'
import './App.css'

function App() {

const keypadDisplay = document.querySelector('.keypad-display');
const keypadContainer = document.querySelector('.keypad-display-container') as HTMLElement

  return (
    <div className='App'>
      <div className='keypad-container'>
      <div className='keypad-display-container'>
        <p className='keypad-display' />
      </div>
      <Keypad
        onNumberClick={(number) => {
          if (keypadDisplay) {

            if (keypadDisplay.textContent?.length === 4 && typeof number === 'number') {
              return;
            }

            if (keypadDisplay.textContent?.length === 0 && typeof number === 'number') {
              keypadContainer.style.backgroundColor = '#34C0AE';
            }

            if (number === '✕') {
              keypadDisplay.textContent = keypadDisplay.textContent?.slice(0, -1) || '';
            }

            else if (number === '✓') {
              const code = keypadDisplay.textContent;
              keypadContainer.style.backgroundColor = code === '0000' ? '#54B95C' : '#B03636';
              keypadDisplay.textContent = '';
            }

            else{
              keypadDisplay.textContent += number.toString();
            }
          }
        }}
      />
      </div>
    </div>
  )
}

export default App
