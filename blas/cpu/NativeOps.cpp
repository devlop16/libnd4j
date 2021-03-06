//
// Created by agibsonccc on 2/21/16.
//

#include "../NativeOps.h"
#include "../NativeOpExcutioner.h"
#include <pointercast.h>

class DoubleNativeOpExecutioner : public NativeOpExcutioner<double> {
private:
    static DoubleNativeOpExecutioner *DOUBLE_INSTANCE;
public:
    static DoubleNativeOpExecutioner * getInstance() {
        if(DOUBLE_INSTANCE == NULL)
            DOUBLE_INSTANCE = new DoubleNativeOpExecutioner();
        return DOUBLE_INSTANCE;
    }
};

class FloatNativeOpExecutioner : public NativeOpExcutioner<float> {
private:
    static FloatNativeOpExecutioner *FLOAT_INSTANCE ;
public:
    static FloatNativeOpExecutioner * getInstance() {
        if(FLOAT_INSTANCE == NULL)
            FLOAT_INSTANCE = new FloatNativeOpExecutioner();
        return FLOAT_INSTANCE;
    }
};




FloatNativeOpExecutioner *FloatNativeOpExecutioner::FLOAT_INSTANCE = NULL;
DoubleNativeOpExecutioner *DoubleNativeOpExecutioner::DOUBLE_INSTANCE = NULL;



/**
 *
 * @param opNum
 * @param x
 * @param xShapeInfo
 * @param extraParams
 */
double   NativeOps::execIndexReduceScalarDouble(Nd4jPointer *extraPointers,int opNum,
                                                Nd4jPointer x,
                                                Nd4jPointer xShapeInfo,
                                                Nd4jPointer extraParams) {
    double *xPointer = reinterpret_cast<double *>(x);
    int *xShapeInfoPointer = reinterpret_cast<int *>(xShapeInfo);
    double *extraParamsPointer = reinterpret_cast<double *>(extraParams);
    return DoubleNativeOpExecutioner::getInstance()->execIndexReduceScalar(opNum,xPointer,xShapeInfoPointer,extraParamsPointer);

}

/**
 *
 * @param opNum
 * @param x
 * @param xShapeInfo
 * @param extraParams
 * @param result
 * @param resultShapeInfoBuffer
 * @param dimension
 * @param dimensionLength
 */
void   NativeOps::execIndexReduceDouble(Nd4jPointer *extraPointers,int opNum,
                                        Nd4jPointer x,
                                        Nd4jPointer xShapeInfo,
                                        Nd4jPointer extraParams,
                                        Nd4jPointer result,
                                        Nd4jPointer resultShapeInfoBuffer,
                                        Nd4jPointer dimension, int dimensionLength) {
    double *xPointer = reinterpret_cast<double *>(x);
    int *xShapeInfoPointer = reinterpret_cast<int *>(xShapeInfo);
    double *extraParamsPointer = reinterpret_cast<double *>(extraParams);
    double *resultPointer = reinterpret_cast<double *>(result);
    int *resultShapeInfoPointer = reinterpret_cast<int *>(resultShapeInfoBuffer);
    int *dimensionPointer = reinterpret_cast<int *>(dimension);
    DoubleNativeOpExecutioner::getInstance()->execIndexReduce(opNum,xPointer,xShapeInfoPointer,extraParamsPointer,resultPointer,resultShapeInfoPointer,dimensionPointer,dimensionLength);


}
/**
 *
 * @param opNum
 * @param x
 * @param xShapeInfo
 * @param y
 * @param yShapeInfo
 * @param result
 * @param resultShapeInfo
 * @param dimension
 * @param dimensionLength
 */
void   NativeOps::execBroadcastDouble(Nd4jPointer *extraPointers,int opNum,
                                      Nd4jPointer x,
                                      Nd4jPointer xShapeInfo,
                                      Nd4jPointer y,
                                      Nd4jPointer yShapeInfo,
                                      Nd4jPointer result,
                                      Nd4jPointer resultShapeInfo,
                                      Nd4jPointer dimension, int dimensionLength) {
    double *xPointer = reinterpret_cast<double *>(x);
    int *xShapeInfoPointer = reinterpret_cast<int *>(xShapeInfo);
    double *yPointer = reinterpret_cast<double *>(y);
    int *yShapeInfoPointer = reinterpret_cast<int *>(yShapeInfo);
    double *resultPointer = reinterpret_cast<double *>(result);
    int *resultShapeInfoPointer = reinterpret_cast<int *>(resultShapeInfo);
    int *dimensionPointer = reinterpret_cast<int *>(dimension);
    DoubleNativeOpExecutioner::getInstance()->execBroadcast(
            opNum,
            xPointer,
            xShapeInfoPointer,
            yPointer,
            yShapeInfoPointer,
            resultPointer,
            resultShapeInfoPointer,
            dimensionPointer,
            dimensionLength);

}



/**
 *
 * @param opNum
 * @param dx
 * @param xStride
 * @param y
 * @param yStride
 * @param result
 * @param resultStride
 * @param extraParams
 * @param n
 */
void   NativeOps::execPairwiseTransformDouble(Nd4jPointer *extraPointers,int opNum,
                                              Nd4jPointer dx,
                                              int xStride,
                                              Nd4jPointer y,
                                              int yStride,
                                              Nd4jPointer result,
                                              int resultStride,
                                              Nd4jPointer extraParams, int n) {
    double *xPointer = reinterpret_cast<double *>(dx);
    double *yPointer = reinterpret_cast<double *>(y);
    double *resultPointer = reinterpret_cast<double *>(result);
    double *extraParamsPointer = reinterpret_cast<double *>(extraParams);
    DoubleNativeOpExecutioner::getInstance()->execPairwiseTransform(opNum,xPointer,xStride,yPointer,yStride,resultPointer,resultStride,extraParamsPointer,n);
}

/**
 *
 * @param opNum
 * @param dx
 * @param xShapeInfo
 * @param y
 * @param yShapeInfo
 * @param result
 * @param resultShapeInfo
 * @param extraParams
 * @param n
 * @param xIndexes
 * @param yIndexes
 * @param resultIndexes
 */
void NativeOps::execPairwiseTransformDouble(
        Nd4jPointer *extraPointers,
        int opNum,
        Nd4jPointer dx,
        Nd4jPointer xShapeInfo,
        Nd4jPointer y,
        Nd4jPointer yShapeInfo,
        Nd4jPointer result,
        Nd4jPointer resultShapeInfo,
        Nd4jPointer extraParams,
        Nd4jPointer xIndexes,
        Nd4jPointer yIndexes,
        Nd4jPointer resultIndexes) {
    double *xPointer = reinterpret_cast<double *>(dx);
    int *xShapeInfoPointer = reinterpret_cast<int *>(xShapeInfo);
    double *yPointer = reinterpret_cast<double *>(y);
    int *yShapeInfoPointer = reinterpret_cast<int *>(yShapeInfo);
    double *resultPointer = reinterpret_cast<double *>(result);
    int *resultShapeInfoPointer = reinterpret_cast<int *>(resultShapeInfo);
    double *extraParamsPointer = reinterpret_cast<double *>(extraParams);
    int *xIndexesPointer = reinterpret_cast<int *>(xIndexes);
    int *yIndexesPointer = reinterpret_cast<int *>(yIndexes);
    int *resultIndexesPointer = reinterpret_cast<int *>(resultIndexes);
    DoubleNativeOpExecutioner::getInstance()->execPairwiseTransform(
            opNum,
            xPointer,
            xShapeInfoPointer,
            yPointer,
            yShapeInfoPointer,
            resultPointer,
            resultShapeInfoPointer,
            extraParamsPointer,
            xIndexesPointer,
            yIndexesPointer,
            resultIndexesPointer);
}

/**
 *
 * @param opNum
 * @param dx
 * @param xShapeInfo
 * @param y
 * @param yShapeInfo
 * @param result
 * @param resultShapeInfo
 * @param extraParams
 * @param n
 */
void NativeOps::execPairwiseTransformDouble(
        Nd4jPointer *extraPointers,
        int opNum,
        Nd4jPointer dx,
        Nd4jPointer  xShapeInfo,
        Nd4jPointer y,
        Nd4jPointer  yShapeInfo,
        Nd4jPointer result,
        Nd4jPointer  resultShapeInfo,
        Nd4jPointer extraParams) {
    double *xPointer = reinterpret_cast<double *>(dx);
    int *xShapeInfoPointer = reinterpret_cast<int *>(xShapeInfo);
    double *yPointer = reinterpret_cast<double *>(y);
    int *yShapeInfoPointer = reinterpret_cast<int *>(yShapeInfo);
    double *resultPointer = reinterpret_cast<double *>(result);
    int *resultShapeInfoPointer = reinterpret_cast<int *>(resultShapeInfo);
    double *extraParamsPointer = reinterpret_cast<double *>(extraParams);
    DoubleNativeOpExecutioner::getInstance()->execPairwiseTransform(
            opNum,
            xPointer,
            xShapeInfoPointer,
            yPointer,
            yShapeInfoPointer,
            resultPointer,
            resultShapeInfoPointer,
            extraParamsPointer);
}

/**
 *
 * @param opNum
 * @param x
 * @param xShapeInfo
 * @param extraParams
 * @param result
 * @param resultShapeInfo
 */
void   NativeOps::execReduceDouble(
        Nd4jPointer *extraPointers,
        int opNum,
        Nd4jPointer x,
        Nd4jPointer xShapeInfo,
        Nd4jPointer extraParams,
        Nd4jPointer result,
        Nd4jPointer resultShapeInfo) {
    double *xPointer = reinterpret_cast<double *>(x);
    int *xShapeInfoPointer = reinterpret_cast<int *>(xShapeInfo);
    double *resultPointer = reinterpret_cast<double *>(result);
    double *extraParamsPointer = reinterpret_cast<double *>(extraParams);
    resultPointer[0] = DoubleNativeOpExecutioner::getInstance()->execReduceScalar(
            opNum,
            xPointer,
            xShapeInfoPointer,
            extraParamsPointer);

}

/**
 *
 * @param opNum
 * @param x
 * @param xShapeInfo
 * @param extraParams
 * @param result
 * @param resultShapeInfo
 */
void   NativeOps::execReduceDouble(Nd4jPointer *extraPointers,int opNum,
                                   Nd4jPointer x,
                                   Nd4jPointer xShapeInfo,
                                   Nd4jPointer extraParams,
                                   Nd4jPointer result,
                                   Nd4jPointer resultShapeInfo,
                                   Nd4jPointer dimension,int dimensionLength) {
    double *xPointer = reinterpret_cast<double *>(x);
    int *xShapeInfoPointer = reinterpret_cast<int *>(xShapeInfo);
    double *resultPointer = reinterpret_cast<double *>(result);
    int *resultShapeInfoPointer = reinterpret_cast<int *>(resultShapeInfo);
    double *extraParamsPointer = reinterpret_cast<double *>(extraParams);
    int *dimensionPointer = reinterpret_cast<int *>(dimension);
    DoubleNativeOpExecutioner::getInstance()->execReduce(opNum,xPointer,xShapeInfoPointer,extraParamsPointer,resultPointer,resultShapeInfoPointer,dimensionPointer,dimensionLength);

}

/**
 *
 * @param opNum
 * @param x
 * @param xShapeInfo
 * @param extraParams
 * @return
 */
double NativeOps::execReduceScalarDouble(Nd4jPointer *extraPointers,int opNum,
                                         Nd4jPointer x,
                                         Nd4jPointer xShapeInfo,
                                         Nd4jPointer extraParams) {
    double *xPointer = reinterpret_cast<double *>(x);
    int *xShapeInfoPointer = reinterpret_cast<int *>(xShapeInfo);
    double *extraParamsPointer = reinterpret_cast<double *>(extraParams);
    return DoubleNativeOpExecutioner::getInstance()->execReduceScalar(opNum,xPointer,xShapeInfoPointer,extraParamsPointer);
}

/**
 *
 * @param opNum
 * @param x
 * @param xShapeInfo
 * @param extraParamsVals
 * @param y
 * @param yShapeInfo
 * @param result
 * @param resultShapeInfo
 */
void   NativeOps::execReduce3Double(Nd4jPointer *extraPointers,int opNum,
                                    Nd4jPointer x,
                                    Nd4jPointer xShapeInfo,
                                    Nd4jPointer extraParamsVals,
                                    Nd4jPointer y,
                                    Nd4jPointer yShapeInfo,
                                    Nd4jPointer result,
                                    Nd4jPointer resultShapeInfo) {
    double *xPointer = reinterpret_cast<double *>(x);
    int *xShapeInfoPointer = reinterpret_cast<int *>(xShapeInfo);
    double *yPointer = reinterpret_cast<double *>(y);
    int *yShapeInfoPointer = reinterpret_cast<int *>(yShapeInfo);
    double *resultPointer = reinterpret_cast<double *>(result);
    int *resultShapeInfoPointer = reinterpret_cast<int *>(resultShapeInfo);
    double *extraParamsPointer = reinterpret_cast<double *>(extraParamsVals);
    DoubleNativeOpExecutioner::getInstance()->execReduce3(opNum,xPointer,xShapeInfoPointer,extraParamsPointer,yPointer,yShapeInfoPointer,resultPointer,resultShapeInfoPointer);
}

/**
 *
 * @param opNum
 * @param x
 * @param xShapeInfo
 * @param extraParamsVals
 * @param y
 * @param yShapeInfo
 */
double   NativeOps::execReduce3ScalarDouble(Nd4jPointer *extraPointers,int opNum,
                                            Nd4jPointer x,
                                            Nd4jPointer xShapeInfo,
                                            Nd4jPointer extraParamsVals,
                                            Nd4jPointer y,
                                            Nd4jPointer yShapeInfo) {
    double *xPointer = reinterpret_cast<double *>(x);
    int *xShapeInfoPointer = reinterpret_cast<int *>(xShapeInfo);
    double *yPointer = reinterpret_cast<double *>(y);
    int *yShapeInfoPointer = reinterpret_cast<int *>(yShapeInfo);
    double *extraParamsPointer = reinterpret_cast<double *>(extraParamsVals);
    return DoubleNativeOpExecutioner::getInstance()->execReduce3Scalar(opNum,xPointer,xShapeInfoPointer,extraParamsPointer,yPointer,yShapeInfoPointer);
}
/**
 *
 * @param opNum
 * @param x
 * @param xShapeInfo
 * @param extraParamsVals
 * @param y
 * @param yShapeInfo
 * @param result
 * @param resultShapeInfoBuffer
 * @param dimension
 * @param dimensionLength
 */
void   NativeOps::execReduce3Double(Nd4jPointer *extraPointers,int opNum,
                                    Nd4jPointer x,
                                    Nd4jPointer xShapeInfo,
                                    Nd4jPointer extraParamsVals,
                                    Nd4jPointer y,
                                    Nd4jPointer yShapeInfo,
                                    Nd4jPointer result,
                                    Nd4jPointer resultShapeInfoBuffer,
                                    Nd4jPointer dimension,
                                    int dimensionLength) {
    double *xPointer = reinterpret_cast<double *>(x);
    int *xShapeInfoPointer = reinterpret_cast<int *>(xShapeInfo);
    double *yPointer = reinterpret_cast<double *>(y);
    int *yShapeInfoPointer = reinterpret_cast<int *>(yShapeInfo);
    double *resultPointer = reinterpret_cast<double *>(result);
    int *resultShapeInfoPointer = reinterpret_cast<int *>(resultShapeInfoBuffer);
    double *extraParamsPointer = reinterpret_cast<double *>(extraParamsVals);
    int *dimensionPointer = reinterpret_cast<int *>(dimension);
    DoubleNativeOpExecutioner::getInstance()->execReduce3(opNum,
                                                          xPointer,
                                                          xShapeInfoPointer,
                                                          extraParamsPointer,
                                                          yPointer,
                                                          yShapeInfoPointer,
                                                          resultPointer,
                                                          resultShapeInfoPointer,
                                                          dimensionPointer,
                                                          dimensionLength);

}
/**
 *
 * @param opNum
 * @param x
 * @param xStride
 * @param result
 * @param resultStride
 * @param scalar
 * @param extraParams
 * @param n
 */
void   NativeOps::execScalarDouble(
        Nd4jPointer *extraPointers,
        int opNum,
        Nd4jPointer x,
        int xStride,
        Nd4jPointer result,
        int resultStride,
        double scalar,
        Nd4jPointer extraParams,
        int n) {
    double *xPointer = reinterpret_cast<double *>(x);
    double *resultPointer = reinterpret_cast<double *>(result);
    double *extraParamsPointer = reinterpret_cast<double *>(extraParams);
    DoubleNativeOpExecutioner::getInstance()->execScalar(
            opNum,
            xPointer,
            xStride,
            resultPointer,
            resultStride,
            scalar,
            extraParamsPointer,
            n);

}

/**
 *
 * @param opNum
 * @param x
 * @param xShapeInfo
 * @param result
 * @param resultShapeInfo
 * @param scalar
 * @param extraParams
 * @param n
 */
void NativeOps::execScalarDouble(
        Nd4jPointer *extraPointers,
        int opNum,
        Nd4jPointer x,
        Nd4jPointer xShapeInfo,
        Nd4jPointer result,
        Nd4jPointer resultShapeInfo,
        double scalar,
        Nd4jPointer extraParams) {
    double *xPointer = reinterpret_cast<double *>(x);
    int *xShapeInfoPointer = reinterpret_cast<int *>(xShapeInfo);
    double *resultPointer = reinterpret_cast<double *>(result);
    int *resultShapeInfoPointer = reinterpret_cast<int *>(resultShapeInfo);
    double *extraParamsPointer = reinterpret_cast<double *>(extraParams);
    DoubleNativeOpExecutioner::getInstance()->execScalar(
            opNum,
            xPointer,
            xShapeInfoPointer,
            resultPointer,
            resultShapeInfoPointer,
            scalar,
            extraParamsPointer);
}

/**
 *
 * @param opNum
 * @param x
 * @param xShapeInfo
 * @param result
 * @param resultShapeInfo
 * @param scalar
 * @param extraParams
 * @param n
 * @param xIndexes
 * @param resultIndexes
 */
void NativeOps::execScalarDouble(
        Nd4jPointer *extraPointers,
        int opNum,
        Nd4jPointer x,
        Nd4jPointer xShapeInfo,
        Nd4jPointer result,
        Nd4jPointer resultShapeInfo,
        double scalar,
        Nd4jPointer extraParams,
        int n,
        Nd4jPointer xIndexes,
        Nd4jPointer resultIndexes) {
    double *xPointer = reinterpret_cast<double *>(x);
    int *xShapeInfoPointer = reinterpret_cast<int *>(xShapeInfo);
    double *resultPointer = reinterpret_cast<double *>(result);
    int *resultShapeInfoPointer = reinterpret_cast<int *>(resultShapeInfo);
    double *extraParamsPointer = reinterpret_cast<double *>(extraParams);
    int *xIndexesPointer = reinterpret_cast<int *>(xIndexes);
    int *resultIndexesPointer = reinterpret_cast<int *>(resultIndexes);
    DoubleNativeOpExecutioner::getInstance()->execScalar(
            opNum,
            xPointer,
            xShapeInfoPointer,
            resultPointer,
            resultShapeInfoPointer,
            scalar,
            extraParamsPointer,
            xIndexesPointer,
            resultIndexesPointer);

}
/**
 *
 * @param opNum
 * @param x
 * @param xShapeInfo
 * @param extraParams
 */
double   NativeOps::execSummaryStatsScalarDouble(Nd4jPointer *extraPointers,int opNum,Nd4jPointer x,
                                                 Nd4jPointer xShapeInfo,
                                                 Nd4jPointer extraParams,bool biasCorrected) {
    double *xPointer = reinterpret_cast<double *>(x);
    int *xShapeInfoPointer = reinterpret_cast<int *>(xShapeInfo);
    double *extraParamsPointer = reinterpret_cast<double *>(extraParams);
    return DoubleNativeOpExecutioner::getInstance()->execSummaryStatsScalar(
            opNum,
            xPointer,
            xShapeInfoPointer,
            extraParamsPointer,biasCorrected);
}
/**
 *
 * @param opNum
 * @param x
 * @param xShapeInfo
 * @param extraParams
 * @param result
 * @param resultShapeInfo
 */
void   NativeOps::execSummaryStatsDouble(Nd4jPointer *extraPointers,int opNum,
                                         Nd4jPointer x,
                                         Nd4jPointer xShapeInfo,
                                         Nd4jPointer extraParams,
                                         Nd4jPointer result,
                                         Nd4jPointer resultShapeInfo,bool biasCorrected) {
    double *xPointer = reinterpret_cast<double *>(x);
    int *xShapeInfoPointer = reinterpret_cast<int *>(xShapeInfo);
    double *resultPointer = reinterpret_cast<double *>(result);
    int *resultShapeInfoPointer = reinterpret_cast<int *>(resultShapeInfo);
    double *extraParamsPointer = reinterpret_cast<double *>(extraParams);
    DoubleNativeOpExecutioner::getInstance()->execSummaryStats(
            opNum,
            xPointer,
            xShapeInfoPointer,
            extraParamsPointer,
            resultPointer,
            resultShapeInfoPointer,
            biasCorrected);
}
/**
 *
 * @param opNum
 * @param x
 * @param xShapeInfo
 * @param extraParams
 * @param result
 * @param resultShapeInfoBuffer
 * @param dimension
 * @param dimensionLength
 */
void   NativeOps::execSummaryStatsDouble(Nd4jPointer *extraPointers,int opNum,Nd4jPointer x,
                                         Nd4jPointer xShapeInfo,
                                         Nd4jPointer extraParams,
                                         Nd4jPointer result,
                                         Nd4jPointer resultShapeInfoBuffer,
                                         Nd4jPointer dimension, int dimensionLength,bool biasCorrected) {
    double *xPointer = reinterpret_cast<double *>(x);
    int *xShapeInfoPointer = reinterpret_cast<int *>(xShapeInfo);
    double *resultPointer = reinterpret_cast<double *>(result);
    int *resultShapeInfoPointer = reinterpret_cast<int *>(resultShapeInfoBuffer);
    double *extraParamsPointer = reinterpret_cast<double *>(extraParams);
    int *dimensionPointer = reinterpret_cast<int *>(dimension);
    DoubleNativeOpExecutioner::getInstance()->execSummaryStats(
            opNum,
            xPointer,
            xShapeInfoPointer,
            extraParamsPointer,
            resultPointer,
            resultShapeInfoPointer,
            dimensionPointer,
            dimensionLength,biasCorrected);

}
/**
 *
 * @param opNum
 * @param dx
 * @param xStride
 * @param result
 * @param resultStride
 * @param extraParams
 * @param n
 */
void   NativeOps::execTransformDouble(Nd4jPointer *extraPointers,int opNum,
                                      Nd4jPointer dx,
                                      int xStride,
                                      Nd4jPointer result,
                                      int resultStride,
                                      Nd4jPointer extraParams, int n) {
    double *xPointer = reinterpret_cast<double *>(dx);
    double *resultPointer = reinterpret_cast<double *>(result);
    double *extraParamsPointer = reinterpret_cast<double *>(extraParams);
    DoubleNativeOpExecutioner::getInstance()->execTransform(opNum,xPointer,xStride,resultPointer,resultStride,extraParamsPointer,n);
}

/**
 *
 * @param opNum
 * @param dx
 * @param xShapeInfo
 * @param result
 * @param resultShapeInfo
 * @param extraParams
 * @param n
 */
void   NativeOps::execTransformDouble(
        Nd4jPointer *extraPointers
        ,int opNum,
        Nd4jPointer dx,
        Nd4jPointer xShapeInfo,
        Nd4jPointer result,
        Nd4jPointer resultShapeInfo,
        Nd4jPointer extraParams) {
    double *xPointer = reinterpret_cast<double *>(dx);
    int *xShapeInfoPointer = reinterpret_cast<int *>(xShapeInfo);
    double *resultPointer = reinterpret_cast<double *>(result);
    int *resultShapeInfoPointer = reinterpret_cast<int *>(resultShapeInfo);
    double *extraParamsPointer = reinterpret_cast<double *>(extraParams);
    DoubleNativeOpExecutioner::getInstance()->execTransform(
            opNum,
            xPointer,
            xShapeInfoPointer,
            resultPointer,
            resultShapeInfoPointer,
            extraParamsPointer);
}

/**
 *
 * @param opNum
 * @param dx
 * @param xShapeInfo
 * @param result
 * @param resultShapeInfo
 * @param extraParams
 * @param n
 */
void   NativeOps::execTransformDouble(
        Nd4jPointer *extraPointers,
        int opNum,
        Nd4jPointer dx,
        Nd4jPointer xShapeInfo,
        Nd4jPointer result,
        Nd4jPointer resultShapeInfo,
        Nd4jPointer extraParams,
        Nd4jPointer xIndexes,
        Nd4jPointer resultIndexes) {
    double *xPointer = reinterpret_cast<double *>(dx);
    int *xShapeInfoPointer = reinterpret_cast<int *>(xShapeInfo);
    double *resultPointer = reinterpret_cast<double *>(result);
    int *resultShapeInfoPointer = reinterpret_cast<int *>(resultShapeInfo);
    double *extraParamsPointer = reinterpret_cast<double *>(extraParams);
    int *xIndexesPointer = reinterpret_cast<int *>(xIndexes);
    int *resultIndexesPointer = reinterpret_cast<int *>(resultIndexes);
    DoubleNativeOpExecutioner::getInstance()->execTransform(
            opNum,
            xPointer,
            xShapeInfoPointer,
            resultPointer,
            resultShapeInfoPointer,
            extraParamsPointer,
            xIndexesPointer,
            resultIndexesPointer);

}

/**
 *
 * @param opNum
 * @param x
 * @param xShapeInfo
 * @param extraParams
 */
float   NativeOps::execIndexReduceScalarFloat(Nd4jPointer *extraPointers,int opNum,
                                              Nd4jPointer x,
                                              Nd4jPointer xShapeInfo,
                                              Nd4jPointer extraParams) {
    float *xPointer = reinterpret_cast<float *>(x);
    int *xShapeInfoPointer = reinterpret_cast<int *>(xShapeInfo);
    float *extraParamsPointer = reinterpret_cast<float *>(extraParams);
    return FloatNativeOpExecutioner::getInstance()->execIndexReduceScalar(opNum,xPointer,xShapeInfoPointer,extraParamsPointer);
}

/**
 *
 * @param opNum
 * @param x
 * @param xShapeInfo
 * @param extraParams
 * @param result
 * @param resultShapeInfoBuffer
 * @param dimension
 * @param dimensionLength
 */
void   NativeOps::execIndexReduceFloat(Nd4jPointer *extraPointers,int opNum,
                                       Nd4jPointer x,
                                       Nd4jPointer xShapeInfo,
                                       Nd4jPointer extraParams,
                                       Nd4jPointer result,
                                       Nd4jPointer resultShapeInfoBuffer,
                                       Nd4jPointer dimension, int dimensionLength) {
    float *xPointer = reinterpret_cast<float *>(x);
    int *xShapeInfoPointer = reinterpret_cast<int *>(xShapeInfo);
    float *extraParamsPointer = reinterpret_cast<float *>(extraParams);
    float *resultPointer = reinterpret_cast<float *>(result);
    int *resultShapeInfoPointer = reinterpret_cast<int *>(resultShapeInfoBuffer);
    int *dimensionPointer = reinterpret_cast<int *>(dimension);
    FloatNativeOpExecutioner::getInstance()->execIndexReduce(opNum,xPointer,xShapeInfoPointer,extraParamsPointer,resultPointer,resultShapeInfoPointer,dimensionPointer,dimensionLength);


}
/**
 *
 * @param opNum
 * @param x
 * @param xShapeInfo
 * @param y
 * @param yShapeInfo
 * @param result
 * @param resultShapeInfo
 * @param dimension
 * @param dimensionLength
 */
void   NativeOps::execBroadcastFloat(Nd4jPointer *extraPointers,int opNum,
                                     Nd4jPointer x,
                                     Nd4jPointer xShapeInfo,
                                     Nd4jPointer y,
                                     Nd4jPointer yShapeInfo,
                                     Nd4jPointer result,
                                     Nd4jPointer resultShapeInfo,
                                     Nd4jPointer dimension, int dimensionLength) {
    float *xPointer = reinterpret_cast<float *>(x);
    int *xShapeInfoPointer = reinterpret_cast<int *>(xShapeInfo);
    float *yPointer = reinterpret_cast<float *>(y);
    int *yShapeInfoPointer = reinterpret_cast<int *>(yShapeInfo);
    float *resultPointer = reinterpret_cast<float *>(result);
    int *resultShapeInfoPointer = reinterpret_cast<int *>(resultShapeInfo);
    int *dimensionPointer = reinterpret_cast<int *>(dimension);
    FloatNativeOpExecutioner::getInstance()->execBroadcast(opNum,xPointer,xShapeInfoPointer,yPointer,yShapeInfoPointer,resultPointer,resultShapeInfoPointer,dimensionPointer,dimensionLength);

}



/**
 *
 * @param opNum
 * @param dx
 * @param xStride
 * @param y
 * @param yStride
 * @param result
 * @param resultStride
 * @param extraParams
 * @param n
 */
void   NativeOps::execPairwiseTransformFloat(
        Nd4jPointer *extraPointers,
        int opNum,
        Nd4jPointer dx,
        int xStride,
        Nd4jPointer y,
        int yStride,
        Nd4jPointer result,
        int resultStride,
        Nd4jPointer extraParams, int n) {
    float *xPointer = reinterpret_cast<float *>(dx);
    float *yPointer = reinterpret_cast<float *>(y);
    float *resultPointer = reinterpret_cast<float *>(result);
    float *extraParamsPointer = reinterpret_cast<float *>(extraParams);
    FloatNativeOpExecutioner::getInstance()->execPairwiseTransform(opNum,xPointer,xStride,yPointer,yStride,resultPointer,resultStride,extraParamsPointer,n);
}

/**
 *
 * @param opNum
 * @param dx
 * @param xShapeInfo
 * @param y
 * @param yShapeInfo
 * @param result
 * @param resultShapeInfo
 * @param extraParams
 * @param n
 * @param xIndexes
 * @param yIndexes
 * @param resultIndexes
 */
void NativeOps::execPairwiseTransformFloat(
        Nd4jPointer *extraPointers,
        int opNum,
        Nd4jPointer dx,
        Nd4jPointer xShapeInfo,
        Nd4jPointer y,
        Nd4jPointer yShapeInfo,
        Nd4jPointer result,
        Nd4jPointer resultShapeInfo,
        Nd4jPointer extraParams,
        Nd4jPointer xIndexes,
        Nd4jPointer yIndexes,
        Nd4jPointer resultIndexes) {
    float *xPointer = reinterpret_cast<float *>(dx);
    int *xShapeInfoPointer = reinterpret_cast<int *>(xShapeInfo);
    float *yPointer = reinterpret_cast<float *>(y);
    int *yShapeInfoPointer = reinterpret_cast<int *>(yShapeInfo);
    float *resultPointer = reinterpret_cast<float *>(result);
    int *resultShapeInfoPointer = reinterpret_cast<int *>(resultShapeInfo);
    float *extraParamsPointer = reinterpret_cast<float *>(extraParams);
    int *xIndexesPointer = reinterpret_cast<int *>(xIndexes);
    int *yIndexesPointer = reinterpret_cast<int *>(yIndexes);
    int *resultIndexesPointer = reinterpret_cast<int *>(resultIndexes);
    FloatNativeOpExecutioner::getInstance()->execPairwiseTransform(
            opNum,
            xPointer,
            xShapeInfoPointer,
            yPointer,
            yShapeInfoPointer,
            resultPointer,
            resultShapeInfoPointer,
            extraParamsPointer,
            xIndexesPointer,
            yIndexesPointer,
            resultIndexesPointer);

}

/**
 *
 * @param opNum
 * @param dx
 * @param xShapeInfo
 * @param y
 * @param yShapeInfo
 * @param result
 * @param resultShapeInfo
 * @param extraParams
 * @param n
 */
void NativeOps::execPairwiseTransformFloat(
        Nd4jPointer *extraPointers,
        int opNum,
        Nd4jPointer dx,
        Nd4jPointer  xShapeInfo,
        Nd4jPointer y,
        Nd4jPointer  yShapeInfo,
        Nd4jPointer result,
        Nd4jPointer  resultShapeInfo,
        Nd4jPointer extraParams) {
    float *xPointer = reinterpret_cast<float *>(dx);
    int *xShapeInfoPointer = reinterpret_cast<int *>(xShapeInfo);
    float *yPointer = reinterpret_cast<float *>(y);
    int *yShapeInfoPointer = reinterpret_cast<int *>(yShapeInfo);
    float *resultPointer = reinterpret_cast<float *>(result);
    int *resultShapeInfoPointer = reinterpret_cast<int *>(resultShapeInfo);
    float *extraParamsPointer = reinterpret_cast<float *>(extraParams);
    FloatNativeOpExecutioner::getInstance()->execPairwiseTransform(opNum,xPointer,xShapeInfoPointer,yPointer,yShapeInfoPointer,resultPointer,resultShapeInfoPointer,extraParamsPointer);

}

/**
 *
 * @param opNum
 * @param x
 * @param xShapeInfo
 * @param extraParams
 * @param result
 * @param resultShapeInfo
 */
void   NativeOps::execReduceFloat(Nd4jPointer *extraPointers,int opNum,
                                  Nd4jPointer x,
                                  Nd4jPointer xShapeInfo,
                                  Nd4jPointer extraParams,
                                  Nd4jPointer result,
                                  Nd4jPointer resultShapeInfo) {
    float *xPointer = reinterpret_cast<float *>(x);
    int *xShapeInfoPointer = reinterpret_cast<int *>(xShapeInfo);
    float *resultPointer = reinterpret_cast<float *>(result);
    int *resultShapeInfoPointer = reinterpret_cast<int *>(resultShapeInfo);
    float *extraParamsPointer = reinterpret_cast<float *>(extraParams);
    int *dimension = (int *) malloc(sizeof(int));
    dimension[0] = shape::MAX_DIMENSION;
    FloatNativeOpExecutioner::getInstance()->execReduce(opNum,xPointer,xShapeInfoPointer,extraParamsPointer,resultPointer,resultShapeInfoPointer,dimension,1);
    free(dimension);
}

/**
 *
 * @param opNum
 * @param x
 * @param xShapeInfo
 * @param extraParams
 * @param result
 * @param resultShapeInfo
 */
void   NativeOps::execReduceFloat(
        Nd4jPointer *extraPointers,
        int opNum,
        Nd4jPointer x,
        Nd4jPointer xShapeInfo,
        Nd4jPointer extraParams,
        Nd4jPointer result,
        Nd4jPointer resultShapeInfo,
        Nd4jPointer dimension,
        int dimensionLength) {
    float *xPointer = reinterpret_cast<float *>(x);
    int *xShapeInfoPointer = reinterpret_cast<int *>(xShapeInfo);
    float *resultPointer = reinterpret_cast<float *>(result);
    int *resultShapeInfoPointer = reinterpret_cast<int *>(resultShapeInfo);
    float *extraParamsPointer = reinterpret_cast<float *>(extraParams);
    int *dimensionPointer = reinterpret_cast<int *>(dimension);
    FloatNativeOpExecutioner::getInstance()->execReduce(
            opNum,
            xPointer,
            xShapeInfoPointer,
            extraParamsPointer,
            resultPointer,
            resultShapeInfoPointer,
            dimensionPointer,
            dimensionLength);

}

/**
 *
 * @param opNum
 * @param x
 * @param xShapeInfo
 * @param extraParams
 * @return
 */
float NativeOps::execReduceScalarFloat(
        Nd4jPointer *extraPointers,
        int opNum,
        Nd4jPointer x,
        Nd4jPointer xShapeInfo,
        Nd4jPointer extraParams) {
    float *xPointer = reinterpret_cast<float *>(x);
    int *xShapeInfoPointer = reinterpret_cast<int *>(xShapeInfo);
    float *extraParamsPointer = reinterpret_cast<float *>(extraParams);
    return FloatNativeOpExecutioner::getInstance()->execReduceScalar(opNum,xPointer,xShapeInfoPointer,extraParamsPointer);
}

/**
 *
 * @param opNum
 * @param x
 * @param xShapeInfo
 * @param extraParamsVals
 * @param y
 * @param yShapeInfo
 * @param result
 * @param resultShapeInfo
 */
void   NativeOps::execReduce3Float(
        Nd4jPointer *extraPointers,
        int opNum,
        Nd4jPointer x,
        Nd4jPointer xShapeInfo,
        Nd4jPointer extraParamsVals,
        Nd4jPointer y,
        Nd4jPointer yShapeInfo,
        Nd4jPointer result,
        Nd4jPointer resultShapeInfo) {
    float *xPointer = reinterpret_cast<float *>(x);
    int *xShapeInfoPointer = reinterpret_cast<int *>(xShapeInfo);
    float *yPointer = reinterpret_cast<float *>(y);
    int *yShapeInfoPointer = reinterpret_cast<int *>(yShapeInfo);
    float *resultPointer = reinterpret_cast<float *>(result);
    int *resultShapeInfoPointer = reinterpret_cast<int *>(resultShapeInfo);
    float *extraParamsPointer = reinterpret_cast<float *>(extraParamsVals);
    FloatNativeOpExecutioner::getInstance()->execReduce3(
            opNum,
            xPointer,
            xShapeInfoPointer,
            extraParamsPointer,
            yPointer,
            yShapeInfoPointer,
            resultPointer,
            resultShapeInfoPointer);

}

/**
 *
 * @param opNum
 * @param x
 * @param xShapeInfo
 * @param extraParamsVals
 * @param y
 * @param yShapeInfo
 */
float   NativeOps::execReduce3ScalarFloat(Nd4jPointer *extraPointers,int opNum,
                                          Nd4jPointer x,
                                          Nd4jPointer xShapeInfo,
                                          Nd4jPointer extraParamsVals,
                                          Nd4jPointer y,
                                          Nd4jPointer yShapeInfo) {
    float *xPointer = reinterpret_cast<float *>(x);
    int *xShapeInfoPointer = reinterpret_cast<int *>(xShapeInfo);
    float *yPointer = reinterpret_cast<float *>(y);
    int *yShapeInfoPointer = reinterpret_cast<int *>(yShapeInfo);
    float *extraParamsPointer = reinterpret_cast<float *>(extraParamsVals);
    return FloatNativeOpExecutioner::getInstance()->execReduce3Scalar(opNum,xPointer,xShapeInfoPointer,extraParamsPointer,yPointer,yShapeInfoPointer);
}
/**
 *
 * @param opNum
 * @param x
 * @param xShapeInfo
 * @param extraParamsVals
 * @param y
 * @param yShapeInfo
 * @param result
 * @param resultShapeInfoBuffer
 * @param dimension
 * @param dimensionLength
 */
void   NativeOps::execReduce3Float(Nd4jPointer *extraPointers,int opNum,
                                   Nd4jPointer x,
                                   Nd4jPointer xShapeInfo,
                                   Nd4jPointer extraParamsVals,
                                   Nd4jPointer y,
                                   Nd4jPointer yShapeInfo,
                                   Nd4jPointer result,
                                   Nd4jPointer resultShapeInfoBuffer,
                                   Nd4jPointer dimension,
                                   int dimensionLength) {
    float *xPointer = reinterpret_cast<float *>(x);
    int *xShapeInfoPointer = reinterpret_cast<int *>(xShapeInfo);
    float *yPointer = reinterpret_cast<float *>(y);
    int *yShapeInfoPointer = reinterpret_cast<int *>(yShapeInfo);
    float *resultPointer = reinterpret_cast<float *>(result);
    int *resultShapeInfoPointer = reinterpret_cast<int *>(resultShapeInfoBuffer);
    float *extraParamsPointer = reinterpret_cast<float *>(extraParamsVals);
    int *dimensionPointer = reinterpret_cast<int *>(dimension);
    FloatNativeOpExecutioner::getInstance()->execReduce3(
            opNum,
            xPointer,
            xShapeInfoPointer,
            extraParamsPointer,
            yPointer,
            yShapeInfoPointer,
            resultPointer,
            resultShapeInfoPointer,
            dimensionPointer,
            dimensionLength);

}
/**
 *
 * @param opNum
 * @param x
 * @param xStride
 * @param result
 * @param resultStride
 * @param scalar
 * @param extraParams
 * @param n
 */
void   NativeOps::execScalarFloat(Nd4jPointer *extraPointers,int opNum,
                                  Nd4jPointer x,
                                  int xStride,
                                  Nd4jPointer result,
                                  int resultStride,
                                  double scalar,
                                  Nd4jPointer extraParams,
                                  int n) {
    float *xPointer = reinterpret_cast<float *>(x);
    float *resultPointer = reinterpret_cast<float *>(result);
    float *extraParamsPointer = reinterpret_cast<float *>(extraParams);
    FloatNativeOpExecutioner::getInstance()->execScalar(opNum,xPointer,xStride,resultPointer,resultStride,scalar,extraParamsPointer,n);

}

/**
 *
 * @param opNum
 * @param x
 * @param xShapeInfo
 * @param result
 * @param resultShapeInfo
 * @param scalar
 * @param extraParams
 * @param n
 */
void NativeOps::execScalarFloat(
        Nd4jPointer *extraPointers,
        int opNum,
        Nd4jPointer x,
        Nd4jPointer xShapeInfo,
        Nd4jPointer result,
        Nd4jPointer resultShapeInfo,
        float scalar,
        Nd4jPointer extraParams) {
    float *xPointer = reinterpret_cast<float *>(x);
    float *resultPointer = reinterpret_cast<float *>(result);
    int *resultShapeInfoPointer = reinterpret_cast<int *>(resultShapeInfo);
    float *extraParamsPointer = reinterpret_cast<float *>(extraParams);
    FloatNativeOpExecutioner::getInstance()->execScalar(opNum,xPointer,resultShapeInfoPointer,resultPointer,resultShapeInfoPointer,scalar,extraParamsPointer);

}

/**
 *
 * @param opNum
 * @param x
 * @param xShapeInfo
 * @param result
 * @param resultShapeInfo
 * @param scalar
 * @param extraParams
 * @param n
 * @param xIndexes
 * @param resultIndexes
 */
void NativeOps::execScalarFloat(
        Nd4jPointer *extraPointers,
        int opNum,
        Nd4jPointer x,
        Nd4jPointer xShapeInfo,
        Nd4jPointer result,
        Nd4jPointer resultShapeInfo,
        double scalar,
        Nd4jPointer extraParams,
        Nd4jPointer xIndexes,
        Nd4jPointer resultIndexes) {
    float *xPointer = reinterpret_cast<float *>(x);
    int *xShapeInfoPointer = reinterpret_cast<int *>(xShapeInfo);
    float *resultPointer = reinterpret_cast<float *>(result);
    int *resultShapeInfoPointer = reinterpret_cast<int *>(resultShapeInfo);
    float *extraParamsPointer = reinterpret_cast<float *>(extraParams);
    int *xIndexesPointer = reinterpret_cast<int *>(xIndexes);
    int *resultIndexesPointer = reinterpret_cast<int *>(resultIndexes);
    FloatNativeOpExecutioner::getInstance()->execScalar(
            opNum,
            xPointer,
            xShapeInfoPointer,
            resultPointer,
            resultShapeInfoPointer,
            scalar,
            extraParamsPointer,
            xIndexesPointer,
            resultIndexesPointer);

}
/**
 *
 * @param opNum
 * @param x
 * @param xShapeInfo
 * @param extraParams
 */
float   NativeOps::execSummaryStatsScalarFloat(
        Nd4jPointer *extraPointers,
        int opNum,
        Nd4jPointer x,
        Nd4jPointer xShapeInfo,
        Nd4jPointer extraParams,bool biasCorrected) {
    float *xPointer = reinterpret_cast<float *>(x);
    int *xShapeInfoPointer = reinterpret_cast<int *>(xShapeInfo);
    float *extraParamsPointer = reinterpret_cast<float *>(extraParams);
    return FloatNativeOpExecutioner::getInstance()->execSummaryStatsScalar(
            opNum,
            xPointer,
            xShapeInfoPointer,
            extraParamsPointer,
            biasCorrected);
}
/**
 *
 * @param opNum
 * @param x
 * @param xShapeInfo
 * @param extraParams
 * @param result
 * @param resultShapeInfo
 */
void   NativeOps::execSummaryStatsFloat(
        Nd4jPointer *extraPointers,
        int opNum,
        Nd4jPointer x,
        Nd4jPointer xShapeInfo,
        Nd4jPointer extraParams,
        Nd4jPointer result,
        Nd4jPointer resultShapeInfo,bool biasCorrected) {
    float *xPointer = reinterpret_cast<float *>(x);
    int *xShapeInfoPointer = reinterpret_cast<int *>(xShapeInfo);
    float *resultPointer = reinterpret_cast<float *>(result);
    int *resultShapeInfoPointer = reinterpret_cast<int *>(resultShapeInfo);
    float *extraParamsPointer = reinterpret_cast<float *>(extraParams);
    FloatNativeOpExecutioner::getInstance()->execSummaryStats(
            opNum,
            xPointer,
            xShapeInfoPointer,
            extraParamsPointer,
            resultPointer,
            resultShapeInfoPointer,
            biasCorrected);
}
/**
 *
 * @param opNum
 * @param x
 * @param xShapeInfo
 * @param extraParams
 * @param result
 * @param resultShapeInfoBuffer
 * @param dimension
 * @param dimensionLength
 */
void   NativeOps::execSummaryStatsFloat(Nd4jPointer *extraPointers,int opNum,Nd4jPointer x,
                                        Nd4jPointer xShapeInfo,
                                        Nd4jPointer extraParams,
                                        Nd4jPointer result,
                                        Nd4jPointer resultShapeInfoBuffer,
                                        Nd4jPointer dimension, int dimensionLength,bool biasCorrected) {
    float *xPointer = reinterpret_cast<float *>(x);
    int *xShapeInfoPointer = reinterpret_cast<int *>(xShapeInfo);
    float *resultPointer = reinterpret_cast<float *>(result);
    int *resultShapeInfoPointer = reinterpret_cast<int *>(resultShapeInfoBuffer);
    float *extraParamsPointer = reinterpret_cast<float *>(extraParams);
    int *dimensionPointer = reinterpret_cast<int *>(dimension);
    FloatNativeOpExecutioner::getInstance()->execSummaryStats(
            opNum,
            xPointer,
            xShapeInfoPointer,
            extraParamsPointer,
            resultPointer,
            resultShapeInfoPointer,
            dimensionPointer,
            dimensionLength,
            biasCorrected);

}
/**
 *
 * @param opNum
 * @param dx
 * @param xStride
 * @param result
 * @param resultStride
 * @param extraParams
 * @param n
 */
void   NativeOps::execTransformFloat(
        Nd4jPointer *extraPointers,
        int opNum,
        Nd4jPointer dx,
        int xStride,
        Nd4jPointer result,
        int resultStride,
        Nd4jPointer extraParams, int n) {
    float *xPointer = reinterpret_cast<float *>(dx);
    float *resultPointer = reinterpret_cast<float *>(result);
    float *extraParamsPointer = reinterpret_cast<float *>(extraParams);
    FloatNativeOpExecutioner::getInstance()->execTransform(opNum,xPointer,xStride,resultPointer,resultStride,extraParamsPointer,n);
}

/**
 *
 * @param opNum
 * @param dx
 * @param xShapeInfo
 * @param result
 * @param resultShapeInfo
 * @param extraParams
 * @param n
 */
void   NativeOps::execTransformFloat(
        Nd4jPointer *extraPointers,
        int opNum,
        Nd4jPointer dx,
        Nd4jPointer xShapeInfo,
        Nd4jPointer result,
        Nd4jPointer resultShapeInfo,
        Nd4jPointer extraParams) {
    float *xPointer = reinterpret_cast<float *>(dx);
    int *xShapeInfoPointer = reinterpret_cast<int *>(xShapeInfo);
    float *resultPointer = reinterpret_cast<float *>(result);
    int *resultShapeInfoPointer = reinterpret_cast<int *>(resultShapeInfo);
    float *extraParamsPointer = reinterpret_cast<float *>(extraParams);
    FloatNativeOpExecutioner::getInstance()->execTransform(opNum,xPointer,xShapeInfoPointer,resultPointer,resultShapeInfoPointer,extraParamsPointer);
}

/**
 *
 * @param opNum
 * @param dx
 * @param xShapeInfo
 * @param result
 * @param resultShapeInfo
 * @param extraParams
 * @param n
 */
void   NativeOps::execTransformFloat(
        Nd4jPointer *extraPointers,
        int opNum,
        Nd4jPointer dx,
        Nd4jPointer xShapeInfo,
        Nd4jPointer result,
        Nd4jPointer resultShapeInfo,
        Nd4jPointer extraParams,
        Nd4jPointer xIndexes,
        Nd4jPointer resultIndexes) {
    float *xPointer = reinterpret_cast<float *>(dx);
    int *xShapeInfoPointer = reinterpret_cast<int *>(xShapeInfo);
    float *resultPointer = reinterpret_cast<float *>(result);
    int *resultShapeInfoPointer = reinterpret_cast<int *>(resultShapeInfo);
    float *extraParamsPointer = reinterpret_cast<float *>(extraParams);
    int *xIndexesPointer = reinterpret_cast<int *>(xIndexes);
    int *resultIndexesPointer = reinterpret_cast<int *>(resultIndexes);
    FloatNativeOpExecutioner::getInstance()->execTransform(
            opNum,
            xPointer,
            xShapeInfoPointer,
            resultPointer,
            resultShapeInfoPointer,
            extraParamsPointer,
            xIndexesPointer,
            resultIndexesPointer);

}
