import unittest
import HelloWorld

class TestHello(unittest.TestCase):
    def test_add1(self):
        # test 1
        instance = HelloWorld.Hello()
        result = instance.add(2, 3)
        self.assertEqual(result, 5)

    def test_add2(self):
        # test2
        instance = HelloWorld.Hello()
        result = instance.add(3, 5)
        self.assertEqual(result, 8)

        # if instance.add(2, 3) != 5:
        #     print("TEST FAILED")
        #     exit(1)
        # print("TEST PASSED")

if __name__ == "__main__":
    unittest.main()
    # test = TestHello()
    # test.test_add()