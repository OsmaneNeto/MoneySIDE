// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCompareBitmapCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTPrimitives.h>
#import <Leadtools/LTRasterCommand.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCompareBitmapCommand : LTRasterCommand

@property (nonatomic, assign, nullable) LeadMatrix *alignment;
@property (nonatomic, assign) LTRasterColor* modifiedBackground;
@property (nonatomic, assign) LTRasterColor* modifiedForeground;
@property (nonatomic, assign) LTRasterColor* outputAddition;
@property (nonatomic, assign) LTRasterColor* outputBackground;
@property (nonatomic, assign) LTRasterColor* outputChange;
@property (nonatomic, assign) LTRasterColor* outputDeletion;
@property (nonatomic, assign) LTRasterColor* outputExternal;
@property (nonatomic, assign, readonly) LTRasterImage* outputImage;
@property (nonatomic, assign) LTRasterColor* outputMatch;
@property (nonatomic, assign) LTRasterColor* referenceBackground;
@property (nonatomic, assign) LTRasterColor* referenceForeground;
@property (nonatomic, assign) LTRasterImage* referenceImage;
@property (nonatomic, assign) NSUInteger threshold;

@end

NS_ASSUME_NONNULL_END
