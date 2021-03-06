//
// Copyright (c) 2002-2015 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//

#ifndef COMPILER_TRANSLATOR_OPERATOR_H_
#define COMPILER_TRANSLATOR_OPERATOR_H_

//
// Operators used by the high-level (parse tree) representation.
//
enum TOperator
{
    EOpNull,  // if in a node, should only mean a node is still being built
    EOpFunctionCall,

    //
    // Unary operators
    //

    EOpNegative,
    EOpPositive,
    EOpLogicalNot,
    EOpBitwiseNot,

    EOpPostIncrement,
    EOpPostDecrement,
    EOpPreIncrement,
    EOpPreDecrement,

    //
    // binary operations (ones with special GLSL syntax are used in TIntermBinary nodes, others in
    // TIntermAggregate nodes)
    //

    EOpAdd,
    EOpSub,
    EOpMul,
    EOpDiv,
    EOpIMod,

    EOpEqual,
    EOpNotEqual,
    EOpLessThan,
    EOpGreaterThan,
    EOpLessThanEqual,
    EOpGreaterThanEqual,

    EOpEqualComponentWise,
    EOpNotEqualComponentWise,
    EOpLessThanComponentWise,
    EOpLessThanEqualComponentWise,
    EOpGreaterThanComponentWise,
    EOpGreaterThanEqualComponentWise,

    EOpComma,

    EOpVectorTimesScalar,
    EOpVectorTimesMatrix,
    EOpMatrixTimesVector,
    EOpMatrixTimesScalar,
    EOpMatrixTimesMatrix,

    EOpLogicalOr,
    EOpLogicalXor,
    EOpLogicalAnd,

    EOpBitShiftLeft,
    EOpBitShiftRight,

    EOpBitwiseAnd,
    EOpBitwiseXor,
    EOpBitwiseOr,

    EOpIndexDirect,
    EOpIndexIndirect,
    EOpIndexDirectStruct,
    EOpIndexDirectInterfaceBlock,

    //
    // Built-in functions mapped to operators (either unary or with multiple parameters)
    //

    EOpRadians,
    EOpDegrees,
    EOpSin,
    EOpCos,
    EOpTan,
    EOpAsin,
    EOpAcos,
    EOpAtan,

    EOpSinh,
    EOpCosh,
    EOpTanh,
    EOpAsinh,
    EOpAcosh,
    EOpAtanh,

    EOpPow,
    EOpExp,
    EOpLog,
    EOpExp2,
    EOpLog2,
    EOpSqrt,
    EOpInverseSqrt,

    EOpAbs,
    EOpSign,
    EOpFloor,
    EOpTrunc,
    EOpRound,
    EOpRoundEven,
    EOpCeil,
    EOpFract,
    EOpMod,
    EOpModf,
    EOpMin,
    EOpMax,
    EOpClamp,
    EOpMix,
    EOpStep,
    EOpSmoothStep,
    EOpIsNan,
    EOpIsInf,

    EOpFloatBitsToInt,
    EOpFloatBitsToUint,
    EOpIntBitsToFloat,
    EOpUintBitsToFloat,

    EOpPackSnorm2x16,
    EOpPackUnorm2x16,
    EOpPackHalf2x16,
    EOpUnpackSnorm2x16,
    EOpUnpackUnorm2x16,
    EOpUnpackHalf2x16,

    EOpLength,
    EOpDistance,
    EOpDot,
    EOpCross,
    EOpNormalize,
    EOpFaceForward,
    EOpReflect,
    EOpRefract,

    EOpDFdx,    // Fragment only, OES_standard_derivatives extension
    EOpDFdy,    // Fragment only, OES_standard_derivatives extension
    EOpFwidth,  // Fragment only, OES_standard_derivatives extension

    EOpMulMatrixComponentWise,
    EOpOuterProduct,
    EOpTranspose,
    EOpDeterminant,
    EOpInverse,

    EOpAny,
    EOpAll,
    EOpLogicalNotComponentWise,

    //
    // Branch
    //

    EOpKill,  // Fragment only
    EOpReturn,
    EOpBreak,
    EOpContinue,

    //
    // Constructors
    //

    EOpConstructInt,
    EOpConstructUInt,
    EOpConstructBool,
    EOpConstructFloat,
    EOpConstructVec2,
    EOpConstructVec3,
    EOpConstructVec4,
    EOpConstructBVec2,
    EOpConstructBVec3,
    EOpConstructBVec4,
    EOpConstructIVec2,
    EOpConstructIVec3,
    EOpConstructIVec4,
    EOpConstructUVec2,
    EOpConstructUVec3,
    EOpConstructUVec4,
    EOpConstructMat2,
    EOpConstructMat2x3,
    EOpConstructMat2x4,
    EOpConstructMat3x2,
    EOpConstructMat3,
    EOpConstructMat3x4,
    EOpConstructMat4x2,
    EOpConstructMat4x3,
    EOpConstructMat4,
    EOpConstructStruct,

    //
    // moves
    //

    EOpAssign,
    EOpInitialize,
    EOpAddAssign,
    EOpSubAssign,

    EOpMulAssign,
    EOpVectorTimesMatrixAssign,
    EOpVectorTimesScalarAssign,
    EOpMatrixTimesScalarAssign,
    EOpMatrixTimesMatrixAssign,

    EOpDivAssign,
    EOpIModAssign,
    EOpBitShiftLeftAssign,
    EOpBitShiftRightAssign,
    EOpBitwiseAndAssign,
    EOpBitwiseXorAssign,
    EOpBitwiseOrAssign,

    //  barriers
    EOpBarrier,
    EOpMemoryBarrier,
    EOpMemoryBarrierAtomicCounter,
    EOpMemoryBarrierBuffer,
    EOpMemoryBarrierImage,
    EOpMemoryBarrierShared,
    EOpGroupMemoryBarrier
};

// Returns the string corresponding to the operator in GLSL
const char *GetOperatorString(TOperator op);

// Say whether or not a binary or unary operation changes the value of a variable.
bool IsAssignment(TOperator op);

#endif  // COMPILER_TRANSLATOR_OPERATOR_H_
