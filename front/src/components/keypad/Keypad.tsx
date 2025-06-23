import { KeypadNumber } from "../keypadNumber/KeypadNumber";
import "./Keypad.css";

interface KeypadProps {
    onNumberClick: (number: number|string) => void;
}

export function Keypad({ onNumberClick }: KeypadProps) {
    const numbers = [1, 2, 3, "✕", 4, "✓"];

    return (
        <div className="keypad">
            {numbers.map((number) => (
                <KeypadNumber
                    key={number}
                    number={number}
                    onClick={onNumberClick}
                />
            ))}
        </div>
    );
}