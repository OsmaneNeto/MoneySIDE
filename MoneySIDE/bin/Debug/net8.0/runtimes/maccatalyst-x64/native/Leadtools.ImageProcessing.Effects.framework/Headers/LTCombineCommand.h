// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCombineCommand.h
//  Leadtools.ImageProcessing.Effects
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTRasterImage.h>
#import <Leadtools/LTPrimitives.h>

typedef NS_OPTIONS(NSUInteger, LTCombineCommandFlags) {
    LTCombineCommandFlagsSourceNop                    = 0x00000000,
    LTCombineCommandFlagsSourceNot                    = 0x00000001,
    LTCombineCommandFlagsSource0                      = 0x00000002,
    LTCombineCommandFlagsSource1                      = 0x00000003,
    LTCombineCommandFlagsDestinationNop               = 0x00000000,
    LTCombineCommandFlagsDestinationNot               = 0x00000010,
    LTCombineCommandFlagsDestination0                 = 0x00000020,
    LTCombineCommandFlagsDestination1                 = 0x00000030,
    LTCombineCommandFlagsOperationAnd                 = 0x00000000,
    LTCombineCommandFlagsOperationOr                  = 0x00000100,
    LTCombineCommandFlagsOperationXor                 = 0x00000200,
    LTCombineCommandFlagsOperationAdd                 = 0x00000300,
    LTCombineCommandFlagsOperationSubtractSource      = 0x00000400,
    LTCombineCommandFlagsOperationSubtractDestination = 0x00000500,
    LTCombineCommandFlagsOperationMultiply            = 0x00000600,
    LTCombineCommandFlagsOperationDivideSource        = 0x00000700,
    LTCombineCommandFlagsOperationDivideDestination   = 0x00000800,
    LTCombineCommandFlagsOperationAverage             = 0x00000900,
    LTCombineCommandFlagsOperationMinimum             = 0x00000A00,
    LTCombineCommandFlagsOperationMaximum             = 0x00000B00,
    LTCombineCommandFlagsResultNop                    = 0x00000000,
    LTCombineCommandFlagsResultNot                    = 0x00001000,
    LTCombineCommandFlagsResult0                      = 0x00002000,
    LTCombineCommandFlagsResult1                      = 0x00003000,
    LTCombineCommandFlagsSourceCopy                   = 0x00000020 | 0x00000000 | 0x00000100,
    LTCombineCommandFlagsSourceMaster                 = 0x00000000,
    LTCombineCommandFlagsSourceRed                    = 0x00010000,
    LTCombineCommandFlagsSourceGreen                  = 0x00020000,
    LTCombineCommandFlagsSourceBlue                   = 0x00030000,
    LTCombineCommandFlagsDestinationMaster            = 0x00000000,
    LTCombineCommandFlagsDestinationRed               = 0x00100000,
    LTCombineCommandFlagsDestinationGreen             = 0x00200000,
    LTCombineCommandFlagsDestinationBlue              = 0x00300000,
    LTCombineCommandFlagsResultMaster                 = 0x00000000,
    LTCombineCommandFlagsResultRed                    = 0x01000000,
    LTCombineCommandFlagsResultGreen                  = 0x02000000,
    LTCombineCommandFlagsResultBlue                   = 0x03000000,
    LTCombineCommandFlagsAbsoluteDifference           = 0x00000C00,
    LTCombineCommandFlagsRawCombine                   = 0x04000000
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCombineCommand : LTRasterCommand

@property (nonatomic, strong, nullable) LTRasterImage *sourceImage;
@property (nonatomic, assign)           LeadRect destinationRectangle;
@property (nonatomic, assign)           LeadPoint sourcePoint;
@property (nonatomic, assign)           LTCombineCommandFlags flags;

- (instancetype)initWithSourceImage:(nullable LTRasterImage *)sourceImage destinationRectangle:(LeadRect)destinationRectangle sourcePoint:(LeadPoint)sourcePoint flags:(LTCombineCommandFlags)flags NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
