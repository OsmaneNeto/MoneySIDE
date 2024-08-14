// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTSmoothCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTRasterRegion.h>
#import <Leadtools/LTRasterImage.h>

#import <Leadtools.ImageProcessing.Core/LTEnums.h>

typedef NS_ENUM(NSInteger, LTSmoothCommandBumpNickType) {
    LTSmoothCommandBumpNickTypeBump = 0x0000,
    LTSmoothCommandBumpNickTypeNick = 0x0001,
};

typedef NS_ENUM(NSInteger, LTSmoothCommandDirectionType) {
    LTSmoothCommandDirectionTypeHorizontal = 0x0000,
    LTSmoothCommandDirectionTypeVertical   = 0x0001,
};

typedef NS_OPTIONS(NSUInteger, LTSmoothCommandFlags) {
    LTSmoothCommandFlagsNone           = 0x0000,
    LTSmoothCommandFlagsSingleRegion   = 0x00000002,
    LTSmoothCommandFlagsLeadRegion     = 0x00000004,
    LTSmoothCommandFlagsImageUnchanged = 0x00000010,
    LTSmoothCommandFlagsFavorLong      = 0x00000100
};

NS_ASSUME_NONNULL_BEGIN

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTSmoothCommandEventArgs : NSObject

@property (nonatomic, assign, readonly) NSInteger startRow;
@property (nonatomic, assign, readonly) NSInteger startColumn;
@property (nonatomic, assign, readonly) NSInteger length;

@property (nonatomic, assign, readonly) LTSmoothCommandBumpNickType bumpNick;
@property (nonatomic, assign, readonly) LTSmoothCommandDirectionType direction;

- (instancetype)init __unavailable;

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

typedef void (^LTSmoothCommandStatus)(LTRasterImage *image, LTSmoothCommandEventArgs *args, LTRemoveStatus *status);

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTSmoothCommand : LTRasterCommand

@property (nonatomic, assign)                     LTSmoothCommandFlags flags;

@property (nonatomic, assign)                     NSInteger length;

@property (nonatomic, strong, readonly, nullable) LTRasterRegion *region;
@property (nonatomic, strong, readonly, nullable) LTRasterImage *imageRegion;

- (instancetype)initWithFlags:(LTSmoothCommandFlags)flags length:(NSInteger)length NS_DESIGNATED_INITIALIZER;

- (BOOL)run:(LTRasterImage *)image progress:(nullable LTRasterCommandProgress)progressHandler status:(nullable LTSmoothCommandStatus)lineRemoveStatus error:(NSError **)error;

@end



@protocol LTSmoothCommandDelegate;

@interface LTSmoothCommand (Deprecated)

@property (nonatomic, weak, nullable) id<LTSmoothCommandDelegate> delegate LT_DEPRECATED_USENEW(19_0, "run:progress:status:error:");

@end

NS_ASSUME_NONNULL_END
