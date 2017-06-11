#pragma once

enum ActionType {
	RELATIONSHIP,
	CHEAT,
	DEATH,
	ARGUE,
	BRAKEUP,
	SEX,
	KILL,
	KISS
};

inline ostream& operator<<(ostream& out, const ActionType& action) {
    switch(action) {
        case RELATIONSHIP: out << " is now in relationship with ";
            break;
        case CHEAT: out << " cheated with ";
            break;
        case DEATH: out << " died ";
            break;
        case ARGUE: out << " argue with ";
            break;
        case BRAKEUP: out << " broke up with ";
            break;
        case SEX: out << " is having sex with ";
            break;
        case KILL: out << " killed ";
        	break;
        case KISS: out << " kissed ";
    }
    return out;
}

inline istream& operator>>(istream& in, ActionType& action) {
    int actionType;
    in >> actionType;

    switch(actionType) {
        case 1: action = RELATIONSHIP;
            break;
        case 2: action = CHEAT;
            break;
        case 3: action = DEATH;
            break;
        case 4: action = ARGUE;
            break;
        case 5: action = BRAKEUP;
            break;
        case 6: action = SEX;
            break;
        case 7: action = KILL;
        	break;
        case 8:  action = KISS;
    }

    return in;
}