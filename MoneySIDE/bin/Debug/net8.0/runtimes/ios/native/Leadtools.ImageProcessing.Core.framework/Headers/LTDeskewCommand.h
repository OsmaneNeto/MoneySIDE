// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTDeskewCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTRasterColor.h>

typedef NS_OPTIONS(NSUInteger, LTDeskewCommandFlags) {
    LTDeskewCommandFlagsDeskewImage                   = 0x00000000,
    LTDeskewCommandFlagsReturnAngleOnly               = 0x00000001,
    LTDeskewCommandFlagsFillExposedArea               = 0x00000000,
    LTDeskewCommandFlagsDoNotFillExposedArea          = 0x00000010,
    LTDeskewCommandFlagsNoThreshold                   = 0x00000000,
    LTDeskewCommandFlagsThreshold                     = 0x00000100,
    LTDeskewCommandFlagsRotateLinear                  = 0x00000000,
    LTDeskewCommandFlagsRotateResample                = 0x00001000,
    LTDeskewCommandFlagsRotateBicubic                 = 0x00002000,
    LTDeskewCommandFlagsDocumentImage                 = 0x00000000,
    LTDeskewCommandFlagsDocumentAndPictures           = 0x00010000,
    LTDeskewCommandFlagsUseNormalRotate               = 0x00000000,
    LTDeskewCommandFlagsUseHighSpeedRotate            = 0x00100000,
    
    LTDeskewCommandFlagsPerformPreProcessing          = 0x00000000,
    LTDeskewCommandFlagsDoNotPerformPreProcessing     = 0x10000000,
    LTDeskewCommandFlagsUseSelectiveDetection         = 0x00000000,
    LTDeskewCommandFlagsUseNormalDetection            = 0x20000000,
    
    LTDeskewCommandFlagsDoNotUseCheckDeskew           = 0x00000000,
    LTDeskewCommandFlagsUseCheckDeskew                = 0x01000000,
    LTDeskewCommandFlagsUseLineDetectionCheckDeskew   = 0x02000000,
    LTDeskewCommandFlagsUseExtendedDeskew             = 0x04000000
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTDeskewCommand : LTRasterCommand

@property (nonatomic, copy)             LTRasterColor *fillColor;
@property (nonatomic, assign)           LTDeskewCommandFlags flags;
@property (nonatomic, assign)           NSUInteger angleRange;
@property (nonatomic, assign)           NSUInteger angleResolution;
@property (nonatomic, assign, readonly) NSInteger angle;

- (instancetype)initWithFillColor:(LTRasterColor *)fillColor flags:(LTDeskewCommandFlags)flags NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
