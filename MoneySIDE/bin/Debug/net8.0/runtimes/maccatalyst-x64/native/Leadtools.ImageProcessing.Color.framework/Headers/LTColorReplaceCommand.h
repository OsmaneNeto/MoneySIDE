// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTColorReplaceCommand.h
//  Leadtools.ImageProcessing.Color
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTRasterColor.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTColorReplaceCommandColor : NSObject

@property (nonatomic, copy) LTRasterColor *color;
@property (nonatomic, assign) NSUInteger fuzziness;

- (instancetype)initWithColor:(LTRasterColor *)color fuzziness:(NSUInteger)fuzziness NS_DESIGNATED_INITIALIZER;

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTColorReplaceCommand : LTRasterCommand

- (instancetype)initWithColors:(NSArray<LTColorReplaceCommandColor *> *)colors hue:(NSInteger)hue saturation:(NSInteger)saturation brightness:(NSInteger)brightness NS_DESIGNATED_INITIALIZER;

@property (nonatomic, strong) NSMutableArray<LTColorReplaceCommandColor *> *colors;

@property (nonatomic, assign) NSInteger hue;
@property (nonatomic, assign) NSInteger saturation;
@property (nonatomic, assign) NSInteger brightness;

@end

NS_ASSUME_NONNULL_END
