



































#ifndef SEQAN_SCORE_SCORE_EDIT_H_
#define SEQAN_SCORE_SCORE_EDIT_H_

namespace SEQAN_NAMESPACE_MAIN {





template <typename TValue>
class Score<TValue, EditDistance> {
public:
    Score() {}
};




typedef Score<int, EditDistance> EditDistanceScore;

template <typename TValue>
inline TValue
scoreMatch(Score<TValue, EditDistance> &) {
    SEQAN_CHECKPOINT;
    return 0;
}


template <typename TValue>
inline TValue
scoreMatch(Score<TValue, EditDistance> const &) {
    SEQAN_CHECKPOINT;
    return 0;
}


template <typename TValue>
inline TValue
scoreMismatch(Score<TValue, EditDistance> &) {
    SEQAN_CHECKPOINT;
    return -1;
}


template <typename TValue>
inline TValue
scoreMismatch(Score<TValue, EditDistance> const &) {
    SEQAN_CHECKPOINT;
    return -1;
}


template <typename TValue>
inline TValue
scoreGapExtend(Score<TValue, EditDistance> &) {
    SEQAN_CHECKPOINT;
    return -1;
}


template <typename TValue>
inline TValue
scoreGapExtend(Score<TValue, EditDistance> const &) {
    SEQAN_CHECKPOINT;
    return -1;
}


template <typename TValue>
inline TValue
scoreGapOpen(Score<TValue, EditDistance> &) {
    SEQAN_CHECKPOINT;
    return -1;
}


template <typename TValue>
inline TValue
scoreGapOpen(Score<TValue, EditDistance> const &) {
    SEQAN_CHECKPOINT;
    return -1;
}

}  

#endif  
