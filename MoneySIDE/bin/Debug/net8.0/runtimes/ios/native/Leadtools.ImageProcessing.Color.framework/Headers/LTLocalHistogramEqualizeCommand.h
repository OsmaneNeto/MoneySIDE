// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTLocalHistogramEqualizeCommand.h
//  Leadtools.ImageProcessing.Color
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools.ImageProcessing.Color/LTEnums.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTLocalHistogramEqualizeCommand : LTRasterCommand

@property (nonatomic, assign) NSInteger width;
@property (nonatomic, assign) NSInteger height;
@property (nonatomic, assign) NSInteger widthExtension;
@property (nonatomic, assign) NSInteger heightExtension;
@property (nonatomic, assign) NSUInteger smooth;
@property (nonatomic, assign) LTHistogramEqualizeType type;

- (instancetype)initWithWidth:(NSInteger)width height:(NSInteger)height widthExtension:(NSInteger)widthExtension heightExtension:(NSInteger)heightExtension smooth:(NSUInteger)smooth type:(LTHistogramEqualizeType)type NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
