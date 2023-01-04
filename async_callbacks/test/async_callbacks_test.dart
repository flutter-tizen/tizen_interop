import 'package:flutter/services.dart';
import 'package:flutter_test/flutter_test.dart';
import 'package:async_callbacks/async_callbacks.dart';

void main() {
  const MethodChannel channel = MethodChannel('async_callbacks');

  TestWidgetsFlutterBinding.ensureInitialized();

  setUp(() {
    channel.setMockMethodCallHandler((MethodCall methodCall) async {
      return '42';
    });
  });

  tearDown(() {
    channel.setMockMethodCallHandler(null);
  });

  test('getPlatformVersion', () async {
    expect(await AsyncCallbacks.platformVersion, '42');
  });
}
