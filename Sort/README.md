이 프로그램은 난수생성함수 프로그램(**gen_list.cpp**)와 7가지 정렬 알고리즘의 실행시간을 비교하는 프로그램(**comp_sort.cpp**)으로 이루어져있다.

첫번째로 <span style="color:red">난수생성함수</span>에서는 사용자가 원하는 숫자(10만 이하)를 입력해 그 숫자만큼 **난수**를 생성해준다.

여기서는 알아보기쉽게 원하는 숫자이하로 랜덤하게 생성해줌. (ex gen_list 1000 => 1~1000 의숫자가 랜덤하게 생성) 

다음으로 정렬 알고리즘 비교프로그램에서는 난수생성함수에서 생성된 숫자가 존재하는 파일을 입력으로 받아 

<span style="color:red">7</span>가지 정렬함수인 **insertSort, bubbleSort, selectSort, quickSort, mergeSort, radixSort, heapSort**를 통해 sort를 한 다음

Clock 함수를 통해 실행시간을 비교한다. 

모든 함수의 정렬이 끝나면 각각의 정렬 시간을 순서대로 "**ResultClk.txt**"에 출력한다.

세부적인 함수의 동작설명은 cpp파일에 주석으로 처리함.
