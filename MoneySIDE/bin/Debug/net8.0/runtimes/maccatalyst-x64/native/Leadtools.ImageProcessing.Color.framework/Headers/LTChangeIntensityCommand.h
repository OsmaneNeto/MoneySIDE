// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTChangeIntensityCommand.h
//  Leadtools.ImageProcessing.Color
//

#import <Leadtools/LTRasterCommand.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTChangeIntensityCommand : LTRasterCommand

@property (nonatomic, assign) NSInteger brightness;

- (instancetype)initWithBrightness:(NSInteger)brightness NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
