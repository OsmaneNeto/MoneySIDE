// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTOcrWord.h
//  Leadtools.Ocr
//

#import <Leadtools/LTPrimitives.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTOcrWord : NSObject <NSCopying>

@property (nonatomic, copy, nullable) NSString *value;

@property (nonatomic, assign)         LeadRect bounds;

@property (nonatomic, assign)         NSUInteger firstCharacterIndex;
@property (nonatomic, assign)         NSUInteger lastCharacterIndex;

@property (nonatomic, assign)         LeadPoint actualBaseStartPoint;
@property (nonatomic, assign)         LeadPoint actualBaseEndPoint;

@end

NS_ASSUME_NONNULL_END
