// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTMinMaxBitsCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTMinMaxBitsCommand : LTRasterCommand

@property (nonatomic, assign, readonly) NSInteger minimumBit;
@property (nonatomic, assign, readonly) NSInteger maximumBit;

@end
