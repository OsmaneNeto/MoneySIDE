// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTAutoColorLevelCommand.h
//  Leadtools.ImageProcessing.Color
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools.ImageProcessing.Color/LTColorLevelCommand.h>

typedef NS_ENUM(NSInteger, LTAutoColorLevelCommandType) {
    LTAutoColorLevelCommandTypeNone      = 0x0000,
    LTAutoColorLevelCommandTypeLevel     = 0x00000001,
    LTAutoColorLevelCommandTypeContrast  = 0x00000002,
    LTAutoColorLevelCommandTypeIntensity = 0x00000003,
};

typedef NS_OPTIONS(NSUInteger, LTAutoColorLevelCommandFlags) {
    LTAutoColorLevelCommandFlagsNone      = 0x0000,
    LTAutoColorLevelCommandFlagsNoProcess = 0x00000004,
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTAutoColorLevelCommand : LTRasterCommand

@property (nonatomic, strong, readonly) LTColorLevelCommandData *master;
@property (nonatomic, strong, readonly) LTColorLevelCommandData *red;
@property (nonatomic, strong, readonly) LTColorLevelCommandData *green;
@property (nonatomic, strong, readonly) LTColorLevelCommandData *blue;
@property (nonatomic, assign)           LTAutoColorLevelCommandType type;
@property (nonatomic, assign)           LTAutoColorLevelCommandFlags flags;
@property (nonatomic, assign)           NSInteger blackClip;
@property (nonatomic, assign)           NSInteger whiteClip;

- (instancetype)initWithType:(LTAutoColorLevelCommandType)type flags:(LTAutoColorLevelCommandFlags)flags;
- (instancetype)initWithBlackClip:(NSInteger)blackClip whiteClip:(NSInteger)whiteClip type:(LTAutoColorLevelCommandType)type flags:(LTAutoColorLevelCommandFlags)flags NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
