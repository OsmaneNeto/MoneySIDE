// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTAutoPageSplitterCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTRasterImage.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTAutoPageSplitterCommand : LTRasterCommand

@property (nonatomic, assign, readonly) NSInteger splittingCoordinate;
@property (nonatomic, strong, readonly) LTRasterImage *firstImage;
@property (nonatomic, strong, readonly) LTRasterImage *secondImage;

@end

NS_ASSUME_NONNULL_END
