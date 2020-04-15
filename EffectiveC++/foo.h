class GamePlayer {
   private:
    static const int NumTurns = 5;
    int scores[NumTurns];
};

class CostEstimate {
   private:
    static const double FudgeFactor;
};

const int GamePlayer::NumTurns;
const double CostEstimate::FudgeFactor = 1.35;

class GamePlayer2 {
   private:
    enum { NumTurns = 5 };
    int scores[NumTurns];
};