#ifndef CHARACTER_TEST_H
#define CHARACTER_TEST_H

#include "gtest/gtest.h"

#include "../header/Character.h"
#include "../header/Sword.h"
#include "../header/Axe.h"

TEST(CharacterTest, Getters1) {
        Equipment* s = new Sword();
        Character* test = new Character("",100,s);

        EXPECT_EQ(test->getName(), "");
        EXPECT_EQ(test->getHealth(), 100);
        EXPECT_EQ(test->getDamage(), 5);
}

TEST(CharacterTest, Getters2) {
        Equipment* s = new Axe();
        Character* test = new Character("",100,s);
        int damage = test->getDamage();

        EXPECT_EQ(test->getName(), "");
        EXPECT_EQ(test->getHealth(), 100);
        EXPECT_TRUE(damage == 3 || damage == 7);
}

TEST(CharacterTest, Setters1) {
        Character* test = new Character("Bad Name That Should Be Replaced Jr.", 1, nullptr);
        test->setName("Good Name");
        test->setHealth(2);

        EXPECT_EQ(test->getName(), "Good Name");
        EXPECT_EQ(test->getHealth(), 2);
}

TEST(CharacterTest, Setters2) {
        Character* test = new Character("Bad Name That Should Be Replaced Jr.", 1, nullptr);
        test->setName(" ");
        test->setHealth(1234567890);

        EXPECT_EQ(test->getName(), " ");
        EXPECT_EQ(test->getHealth(), 1234567890);
}

TEST(CharacterTest, HurtEquip1) {
        Character* test = new Character("Hero", 100, nullptr);
        test->takeDamage(99);
        Equipment* s = new Sword();
        test->addEquipment(s);

        EXPECT_EQ(test->getHealth(), 1);
        EXPECT_EQ(test->getDamage(), 5);
}

TEST(CharacterTest, HurtEquip2) {
        Character* test = new Character("Hero", 50, nullptr);
        test->takeDamage(100);
        Equipment* a = new Axe();
        test->addEquipment(a);
        int damage = test->getDamage();

        EXPECT_EQ(test->getHealth(), -50);
        EXPECT_TRUE(damage == 3 || damage == 7);
}
#endif
