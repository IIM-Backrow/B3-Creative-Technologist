import { useState } from 'react'
import { Keypad } from './components/keypad/Keypad'
import './App.css'

function App() {
  const [code, setCode] = useState<string>('');
  const [containerColor, setContainerColor] = useState<string>('');

  const handleKeypadClick = async (number: number | string) => {
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
        const data = await fetch(`http://192.168.4.1/unlock?code=${code}`)
          .then(response => response.json())
          console.log(data);
          
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
