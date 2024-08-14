// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTApplyMathematicalLogicCommand.h
//  Leadtools.ImageProcessing.Color
//

#import <Leadtools/LTRasterCommand.h>

typedef NS_OPTIONS(NSUInteger, LTApplyMathematicalLogicCommandFlags) {
    LTApplyMathematicalLogicCommandFlagsMaster                      = 0x0000,
    LTApplyMathematicalLogicCommandFlagsRed                         = 0x0001,
    LTApplyMathematicalLogicCommandFlagsGreen                       = 0x0002,
    LTApplyMathematicalLogicCommandFlagsBlue                        = 0x0003,
    
    LTApplyMathematicalLogicCommandFlagsValueDoNothing              = 0x00000000,
    LTApplyMathematicalLogicCommandFlagsValueNot                    = 0x00000010,
    LTApplyMathematicalLogicCommandFlagsValueZero                   = 0x00000020,
    LTApplyMathematicalLogicCommandFlagsValueOne                    = 0x00000030,
    
    LTApplyMathematicalLogicCommandFlagsOperationAnd                = 0x00000000,
    LTApplyMathematicalLogicCommandFlagsOperationOr                 = 0x00000100,
    LTApplyMathematicalLogicCommandFlagsOperationXor                = 0x00000200,
    LTApplyMathematicalLogicCommandFlagsOperationAdd                = 0x00000300,
    LTApplyMathematicalLogicCommandFlagsOperationSubtractFactor     = 0x00000400,
    LTApplyMathematicalLogicCommandFlagsOperationSubtractValue      = 0x00000500,
    LTApplyMathematicalLogicCommandFlagsOperationAbsoluteDifference = 0x00000600,
    LTApplyMathematicalLogicCommandFlagsOperationMultiply           = 0x00000700,
    LTApplyMathematicalLogicCommandFlagsOperationDivisionByFactor   = 0x00000800,
    LTApplyMathematicalLogicCommandFlagsOperationDivisionByValue    = 0x00000900,
    LTApplyMathematicalLogicCommandFlagsOperationAverage            = 0x00000A00,
    LTApplyMathematicalLogicCommandFlagsOperationMinimum            = 0x00000B00,
    LTApplyMathematicalLogicCommandFlagsOperationMaximum            = 0x00000C00,
    
    LTApplyMathematicalLogicCommandFlagsResultDoNothing             = 0x00000000,
    LTApplyMathematicalLogicCommandFlagsResultNot                   = 0x00001000,
    LTApplyMathematicalLogicCommandFlagsResultZero                  = 0x00002000,
    LTApplyMathematicalLogicCommandFlagsResultOne                   = 0x00003000
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTApplyMathematicalLogicCommand : LTRasterCommand

@property (nonatomic, assign) NSInteger factor;
@property (nonatomic, assign) LTApplyMathematicalLogicCommandFlags flags;

- (instancetype)initWithFactor:(NSInteger)factor flags:(LTApplyMathematicalLogicCommandFlags)flags NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
