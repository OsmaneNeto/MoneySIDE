// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTAnisotropicDiffusionCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTPrimitives.h>

typedef NS_OPTIONS(NSUInteger, LTTADAnisotropicDiffusionFlags) {
    LTTADAnisotropicDiffusionFlagsExponentialFlux  = 0x0001,
    LTTADAnisotropicDiffusionFlagsQuadraticFlux    = 0x0002
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTTADAnisotropicDiffusionCommand : LTRasterCommand

@property (nonatomic, assign) NSInteger iterations;
@property (nonatomic, assign) NSInteger kappa;
@property (nonatomic, assign) NSInteger lambda;
@property (nonatomic, assign) LTTADAnisotropicDiffusionFlags flags;

- (instancetype)initWithIterations:(NSInteger)iterations lambda:(NSInteger)lambda kappa:(NSInteger)kappa flags:(LTTADAnisotropicDiffusionFlags)flags NS_DESIGNATED_INITIALIZER;

@end


NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTSRADAnisotropicDiffusionCommand : LTRasterCommand

@property (nonatomic, assign) NSInteger iterations;
@property (nonatomic, assign) NSInteger lambda;
@property (nonatomic, assign) LeadRect rect;

- (instancetype)initWithIterations:(NSInteger)iterations lambda:(NSInteger)lambda rect:(LeadRect)rect NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
