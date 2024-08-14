// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTBrightnessDetectionCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTPrimitives.h>

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTBrightnessDetectionCommand : LTRasterCommand

@property (nonatomic, assign, readonly) float brightnessAmount;

@end
