import './KeypadNumber.css';

interface KeypadNumberProps {
    number: number|string;
    onClick: (number: number|string) => void;
}

export function KeypadNumber({ number, onClick }: KeypadNumberProps) {
    return (
        <button
            className="keypad-number"
            onClick={() => onClick(number)}
        >
            {number}
        </button>
    );
}