// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTPerspectiveDeskewCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTPerspectiveDeskewCommand : LTRasterCommand

@property (nonatomic, assign) bool donotProcessImage;
@property (nonatomic, strong, readonly) NSArray<NSValue *> *corners;

@end
