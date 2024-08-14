// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTAlignImagesCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTRasterImage.h>
#import <Leadtools/LTPrimitives.h>

typedef NS_OPTIONS(NSUInteger, LTRegistrationOptions) {
    LTRegistrationOptionsUnknown      = 0x00000000,
    LTRegistrationOptionsXY           = 0x00000001,
    LTRegistrationOptionsRSXY         = 0x00000002,
    LTRegistrationOptionsAffine6      = 0x00000003,
    LTRegistrationOptionsPerspective  = 0x00000004,
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTAlignImagesCommand : LTRasterCommand

@property (nonatomic, strong, readonly, nullable) LTRasterImage *registeredImage;
@property (nonatomic, strong, nullable)           LTRasterImage *templateImage;
@property (nonatomic, strong, nullable)           NSArray<NSValue *> *referenceImagePoints; //LeadPoint
@property (nonatomic, strong, nullable)           NSArray<NSValue *> *templateImagePoints; //LeadPoint
@property (nonatomic, assign)                     LTRegistrationOptions registrationMethod;

@end

NS_ASSUME_NONNULL_END
