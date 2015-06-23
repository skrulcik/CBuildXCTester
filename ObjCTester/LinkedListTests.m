//
//  LinkedListTests.m
//  CTester
//
//  Created by Scott Krulcik on 6/22/15.
//  Copyright © 2015 Scott Krulcik. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "ctests.h"
#import "linkedlists.h"

@interface LinkedListTests : XCTestCase

@end

@implementation LinkedListTests {
    bool (*intEq)(void *a, void *b);
    void *a;
    void *a_dup;
    void *b;
    void *c;
    
    LL *empty;
    LL *singleton;
    LL *duplicate_a;
    LL *all_elems;
}

bool integerEqualityFunction(void *a, void *b) {
    return *(int *)a == *(int *)b;
}

- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
    a = malloc(sizeof(int));
    a_dup = malloc(sizeof(int));
    b = malloc(sizeof(int));
    c = malloc(sizeof(int));
    *(int *)a = 83;
    *(int *)a_dup = 83;
    *(int *)b = 234;
    *(int *)c = -1234;
    
    intEq = &integerEqualityFunction;
    
    empty = LL_create(intEq);
    singleton = LL_create(intEq);
    duplicate_a = LL_create(intEq);
    all_elems = LL_create(intEq);
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
    
    free(a);
    free(b);
    free(a_dup);
    free(c);
    
    LL_free(empty);
    LL_free(singleton);
    LL_free(duplicate_a);
    LL_free(all_elems);
}

- (void)testInit {
    XCTAssert(LL_create_primitive() != nil);
    XCTAssert(LL_create(intEq) != nil);
}

- (void)testEmpty {
    XCTAssert(LL_isEmpty(empty));
    XCTAssertFalse(LL_isEmpty(singleton));
}

@end
