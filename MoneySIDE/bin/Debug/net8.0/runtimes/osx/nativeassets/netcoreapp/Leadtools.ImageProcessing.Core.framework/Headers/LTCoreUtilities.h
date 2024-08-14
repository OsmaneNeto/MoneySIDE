// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCoreUtilities.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTRasterImage.h>
#import <Leadtools/LTPrimitives.h>

#import <Leadtools.ImageProcessing.Core/LTEnums.h>

typedef NS_ENUM(NSInteger, LTCountLookupTableColorsType) {
    LTCountLookupTableColorsTypeUnsigned = 0x0001,
    LTCountLookupTableColorsTypeSigned   = 0x0002
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTTransformationParameters : NSObject

@property (nonatomic, assign) NSInteger xTranslation;
@property (nonatomic, assign) NSInteger yTranslation;
@property (nonatomic, assign) NSInteger angle;
@property (nonatomic, assign) NSInteger xScale;
@property (nonatomic, assign) NSInteger yScale;

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCountLookupTableColorsResult : NSObject

@property (nonatomic, assign) NSInteger numberOfEntries;
@property (nonatomic, assign) NSInteger firstIndex;

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCoreUtilities : NSObject

+ (nullable LTTransformationParameters *)getTransformationParameters:(LTRasterImage *)image referencePoints:(nullable NSArray<NSValue *> *)referencePoints /*LeadPoint*/ transformedPoints:(nullable NSArray<NSValue *> *)transformedPoints /*LeadPoint*/ error:(NSError **)error NS_SWIFT_NAME(getTransformationParameters(image:referencePoints:transformedPoints:));
+ (BOOL)isRegistrationMark:(LTRasterImage *)image type:(LTRegistrationMarkCommandType)type minScale:(NSInteger)minScale maxScale:(NSInteger)maxScale width:(NSInteger)width height:(NSInteger)height error:(NSError **)error NS_SWIFT_NAME(isRegistrationMark(image:type:minScale:maxScale:width:height:));
+ (nullable NSArray<NSValue *> * /*LeadPoint*/)getRegistrationMarksCenterMass:(LTRasterImage *)image markPoints:(nullable NSArray<NSValue *> *)markPoints /*LeadPoint*/ error:(NSError **)error NS_SWIFT_NAME(getRegistrationMarksCenterMass(image:markPoints:));
+ (nullable LTCountLookupTableColorsResult *)countLookupTableColors:(nullable NSArray<LTRasterColor *> *)lookupTable type:(LTCountLookupTableColorsType)type error:(NSError **)error;
+ (nullable LTCountLookupTableColorsResult *)countLookupTableColorsExt:(nullable NSArray<LTRasterColor16 *> *)lookupTable type:(LTCountLookupTableColorsType)type error:(NSError **)error;

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTImageColorTypeCommand : LTRasterCommand

@property (nonatomic, assign)           LTImageColorTypeCommandFlags flags;
@property (nonatomic, assign, readonly) NSInteger confidence;
@property (nonatomic, assign, readonly) LTImageColorType colorType;

- (instancetype)initWithFlags:(LTImageColorTypeCommandFlags)flags NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
