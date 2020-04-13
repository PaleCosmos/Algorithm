#pragma region LICENSE
//    Copyright 2020 PaleCosmos
//
//    Licensed under the Apache License, Version 2.0 (the "License");
//    you may not use this file except in compliance with the License.
//    You may obtain a copy of the License at
//
//        http://www.apache.org/licenses/LICENSE-2.0
//
//    Unless required by applicable law or agreed to in writing, software
//    distributed under the License is distributed on an "AS IS" BASIS,
//    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//    See the License for the specific language governing permissions and
//    limitations under the License.
#pragma endregion
#include <stdio.h>

//입출력 시간 단축을 위해 C의 입출력 함수를 사용했다.
int main()
{
    int N, A, B;

    do
    {
        printf("테스트 케이스의 수를 입력해주십시오.\n");
        scanf("%d", &N);
    } while (N < 1 || N > 1000000);

    for (int i = 0; i < N; i++)
    {
        printf("두 수를 입력해 주세요 : ");
        scanf("%d %d", &A, &B);
        printf("%d\n", (A + B));
    }

    return 0;
}