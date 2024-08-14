// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTIntensityDetectCommand.h
//  Leadtools.ImageProcessing.Color
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTRasterColor.h>

typedef NS_OPTIONS(NSUInteger, LTIntensityDetectCommandFlags) {
    LTIntensityDetectCommandFlagsMaster     = 0x0000,
    LTIntensityDetectCommandFlagsRed        = 0x0001,
    LTIntensityDetectCommandFlagsGreen      = 0x0010,
    LTIntensityDetectCommandFlagsBlue       = 0x0100
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTIntensityDetectCommand : LTRasterCommand

@property (nonatomic, assign) NSUInteger lowThreshold;
@property (nonatomic, assign) NSUInteger highThreshold;
@property (nonatomic, copy)   LTRasterColor *inColor;
@property (nonatomic, copy)   LTRasterColor *outColor;
@property (nonatomic, assign) LTIntensityDetectCommandFlags channel;

- (instancetype)initWithLow:(NSUInteger)low high:(NSUInteger)high inColor:(LTRasterColor *)inColor outColor:(LTRasterColor *)outColor channel:(LTIntensityDetectCommandFlags)channel NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
