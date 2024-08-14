// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTMaskConvolutionCommand.h
//  Leadtools.ImageProcessing.Effects
//

#import <Leadtools/LTRasterCommand.h>

typedef NS_ENUM(NSInteger, LTMaskConvolutionCommandType) {
    LTMaskConvolutionCommandTypeEmboss        = 0x0000,
    LTMaskConvolutionCommandTypeEdgeDetection = 0x0001,
    LTMaskConvolutionCommandTypeEmbossSplotch = 0x0002,
    LTMaskConvolutionCommandTypeSplotch       = 0x0003
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTMaskConvolutionCommand : LTRasterCommand

@property (nonatomic, assign) NSInteger angle;
@property (nonatomic, assign) NSUInteger depth;
@property (nonatomic, assign) NSUInteger height;
@property (nonatomic, assign) LTMaskConvolutionCommandType type;

- (instancetype)initWithAngle:(NSInteger)angle depth:(NSUInteger)depth height:(NSUInteger)height type:(LTMaskConvolutionCommandType)type NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
