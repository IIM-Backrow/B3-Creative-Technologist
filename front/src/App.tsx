import { useState } from 'react'
import { Keypad } from './components/keypad/Keypad'
import './App.css'

function App() {
  const [code, setCode] = useState<string>('');
  const [containerColor, setContainerColor] = useState<string>('');

  const handleKeypadClick = (number: number | string) => {
    if (code.length === 4 && typeof number === 'number') {
      console.warn('Maximum code length reached');
      return;
    }

    if (code.length === 0 && typeof number === 'number') {
      setContainerColor('#34C0AE');
    }

    if (number === '✕') {
      setCode(prevCode => prevCode.slice(0, -1));
    }
    else if (number === '✓') {
      setContainerColor(code === '0000' ? '#54B95C' : '#B03636');
      setCode('');
    }
    else {
      setCode(prevCode => prevCode + number.toString());
    }
  };

  return (
    <div className='App'>
      <div className='keypad-container'>
        <div 
          className='keypad-display-container'
          style={{ backgroundColor: containerColor }}
        >
          <p className='keypad-display'>{code}</p>
        </div>
        <Keypad onNumberClick={handleKeypadClick} />
      </div>
    </div>
  )
}

export default App
