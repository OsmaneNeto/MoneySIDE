// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTGrayScaleExtendedCommand.h
//  Leadtools.ImageProcessing.Color
//

#import <Leadtools/LTRasterCommand.h>

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTGrayScaleExtendedCommand : LTRasterCommand

@property (nonatomic, assign) NSInteger redFactor;
@property (nonatomic, assign) NSInteger greenFactor;
@property (nonatomic, assign) NSInteger blueFactor;

- (instancetype)initWithRedFactor:(NSInteger)redFactor greenFactor:(NSInteger)greenFactor blueFactor:(NSInteger)blueFactor NS_DESIGNATED_INITIALIZER;

@end
