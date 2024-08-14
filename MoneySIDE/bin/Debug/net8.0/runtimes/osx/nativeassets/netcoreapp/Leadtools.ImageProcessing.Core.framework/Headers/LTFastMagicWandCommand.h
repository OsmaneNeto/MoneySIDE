// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTFastMagicWandCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTPrimitives.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTFastMagicWandCommand : LTRasterCommand

@property (nonatomic, assign) LTRasterImage* sourceImage;
@property (nonatomic, assign) NSInteger x;
@property (nonatomic, assign) NSInteger y;
@property (nonatomic, assign) NSInteger tolerance;
//@property (nonatomic, assign) MAGICWANDHANDLE magicHandle;
@property (nonatomic, assign, readonly) LeadRect objectRectangle;
@property (nonatomic, strong, readonly) NSMutableArray<NSMutableArray<NSNumber *> *> *objectData;

- (instancetype)initWithImage:(LTRasterImage*)sourceImage x:(NSInteger)x y:(NSInteger)y tolerance:(NSInteger)tolerange NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
