// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTBlurDetectionCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTBlurDetectionCommand : LTRasterCommand

@property (nonatomic, assign, readonly) BOOL blurred;
@property (nonatomic, assign, readonly) double blurExtent;

@end
