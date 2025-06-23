import './KeypadNumber.css';

interface KeypadNumberProps {
    number: number;
    onClick: (number: number) => void;
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