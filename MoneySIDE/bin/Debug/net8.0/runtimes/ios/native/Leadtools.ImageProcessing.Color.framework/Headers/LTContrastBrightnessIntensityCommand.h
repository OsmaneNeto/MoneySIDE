// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTContrastBrightnessIntensityCommand.h
//  Leadtools.ImageProcessing.Color
//

#import <Leadtools/LTRasterCommand.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTContrastBrightnessIntensityCommand : LTRasterCommand

@property (nonatomic, assign) NSInteger contrast;
@property (nonatomic, assign) NSInteger brightness;
@property (nonatomic, assign) NSInteger intensity;

- (instancetype)initWithContrast:(NSInteger)contrast brightness:(NSInteger)brightness intensity:(NSInteger)intensity NS_DESIGNATED_INITIALIZER ;

@end

NS_ASSUME_NONNULL_END
