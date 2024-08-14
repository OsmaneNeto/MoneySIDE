// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTConvertToColoredGrayCommand.h
//  Leadtools.ImageProcessing.Color
//

#import <Leadtools/LTRasterCommand.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTConvertToColoredGrayCommand : LTRasterCommand

@property (nonatomic, assign) NSInteger redFactor;
@property (nonatomic, assign) NSInteger greenFactor;
@property (nonatomic, assign) NSInteger blueFactor;
@property (nonatomic, assign) NSInteger redGrayFactor;
@property (nonatomic, assign) NSInteger greenGrayFactor;
@property (nonatomic, assign) NSInteger blueGrayFactor;

- (instancetype)initWithRedFactor:(NSInteger)redFactor greenFactor:(NSInteger)greenFactor blueFactor:(NSInteger)blueFactor redGrayFactor:(NSInteger)redGrayFactor greenGrayFactor:(NSInteger)greenGrayFactor blueGrayFactor:(NSInteger)blueGrayFactor NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
