// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTApplyLinearModalityLookupTableCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools.ImageProcessing.Core/LTEnums.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTApplyLinearModalityLookupTableCommand : LTRasterCommand

@property (nonatomic, assign) double intercept;
@property (nonatomic, assign) double slope;
@property (nonatomic, assign) LTModalityLookupTableCommandFlags flags;

- (instancetype)initWithIntercept:(double)intercept slope:(double)slope flags:(LTModalityLookupTableCommandFlags)flags NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
