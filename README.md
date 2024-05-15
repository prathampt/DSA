<p align="center">
  <img src="https://img.icons8.com/external-tal-revivo-regular-tal-revivo/96/external-readme-is-a-easy-to-build-a-developer-hub-that-adapts-to-the-user-logo-regular-tal-revivo.png" width="100" />
</p>
<p align="center">
    <h1 align="center">DSA</h1>
</p>
<p align="center">
	<img src="https://img.shields.io/github/last-commit/prathampt/DSA?style=flat&logo=git&logoColor=white&color=0080ff" alt="last-commit">
	<img src="https://img.shields.io/github/languages/top/prathampt/DSA?style=flat&color=0080ff" alt="repo-top-language">
	<img src="https://img.shields.io/github/languages/count/prathampt/DSA?style=flat&color=0080ff" alt="repo-language-count">
<p>
<p align="center">
		<em>Developed with: </em>
</p>
<p align="center">
	<img src="https://img.shields.io/badge/C-A8B9CC.svg?style=flat&logo=C&logoColor=black" alt="C">
</p>
<hr>

##  Quick Links

> - [ Overview](#-overview)
> - [ Repository Structure](#-repository-structure)
> - [ Getting Started](#-getting-started)
>   - [ Installation](#-installation)
>   - [ Running DSA](#-running-DSA)
> - [ Contributing](#-contributing)

---

##  Overview
Welcome to our Data Structures and Algorithms repository in C! Here, you'll discover a comprehensive compilation of frequently used data structures and algorithms implemented in the C programming language. This repository encompasses all the code crafted for both DSA-I and DSA-II courses, encompassing every assignment along the way. 

I've taken care to organize everything systematically. Each implementation is neatly categorized and comprises three essential components:

1. **header.h:** This file houses all the necessary structure and function declarations, providing a clear overview of what each component does.
2. **logic.c:** Here's where the magic unfolds! The logic.c file contains all the essential logic behind the functions, ensuring that everything runs smoothly and efficiently.
3. **main.c:** This is your testing ground. In main.c, you can put the code through its paces, ensuring that everything functions as expected.

And in case you're on the lookout for a specific data structure and can't seem to find it, fear not! Simply head over to the dsa2/assignments section, and you might just discover what you're seeking.

Happy exploring and coding! Keep smiling...

---

##  Repository Structure

```sh
└── DSA/
    ├── README.md
    ├── arrayADT
    │   ├── header.h
    │   ├── logic.c
    │   ├── main
    │   └── main.c
    ├── binarySearchTree
    │   ├── header.h
    │   ├── logic.c
    │   ├── main
    │   └── main.c
    ├── circularLinkedListADT
    │   ├── header.h
    │   ├── logic.c
    │   ├── main
    │   └── main.c
    ├── circularQueueUsingArray
    │   ├── header.h
    │   ├── logic.c
    │   ├── main
    │   └── main.c
    ├── doublyLinkedList
    │   ├── header.h
    │   ├── logic.c
    │   ├── main
    │   └── main.c
    ├── dsa1
    │   ├── assignment1
    │   │   ├── assignment1q1
    │   │   ├── assignment1q1.c
    │   │   ├── assignment1q2
    │   │   ├── assignment1q2.c
    │   │   ├── assignment1q3
    │   │   ├── assignment1q3.c
    │   │   ├── assignment1q4
    │   │   ├── assignment1q4.c
    │   │   ├── assignment1q5
    │   │   ├── assignment1q5.c
    │   │   ├── assignment1q6
    │   │   ├── assignment1q6.c
    │   │   ├── assignment1q7
    │   │   └── assignment1q7.c
    │   ├── assignment2
    │   │   ├── assignment2q1
    │   │   ├── assignment2q1.c
    │   │   ├── assignment2q2
    │   │   ├── assignment2q2.c
    │   │   ├── assignment2q3
    │   │   ├── assignment2q3.c
    │   │   ├── assignment2q4
    │   │   ├── assignment2q4.c
    │   │   ├── assignment2q5
    │   │   ├── assignment2q5.c
    │   │   ├── assignment2q6
    │   │   ├── assignment2q6.c
    │   │   ├── assignment2q7
    │   │   ├── assignment2q7.c
    │   │   ├── assignment2q8
    │   │   ├── assignment2q8.c
    │   │   ├── assignment2q9
    │   │   └── assignment2q9.c
    │   ├── assignment3
    │   │   ├── assignment3q1
    │   │   ├── assignment3q1.c
    │   │   ├── assignment3q10
    │   │   ├── assignment3q10.c
    │   │   ├── assignment3q11
    │   │   ├── assignment3q11.c
    │   │   ├── assignment3q12
    │   │   ├── assignment3q12.c
    │   │   ├── assignment3q2
    │   │   ├── assignment3q2.c
    │   │   ├── assignment3q3
    │   │   ├── assignment3q3.c
    │   │   ├── assignment3q4
    │   │   ├── assignment3q4.c
    │   │   ├── assignment3q5
    │   │   ├── assignment3q5.c
    │   │   ├── assignment3q6
    │   │   ├── assignment3q6.c
    │   │   ├── assignment3q7
    │   │   ├── assignment3q7.c
    │   │   ├── assignment3q8
    │   │   ├── assignment3q8.c
    │   │   ├── assignment3q9
    │   │   ├── assignment3q9.c
    │   │   └── temp
    │   ├── assignment4
    │   │   ├── assignment4q1
    │   │   │   ├── header.h
    │   │   │   ├── logic.c
    │   │   │   ├── main
    │   │   │   └── main.c
    │   │   └── assignment4q2
    │   │       ├── header.h
    │   │       ├── logic.c
    │   │       ├── main
    │   │       └── main.c
    │   ├── assignment5
    │   │   ├── assignment5q1.odg
    │   │   ├── assignment5q2.odg
    │   │   ├── assignment5q3.odg
    │   │   ├── assignment5q4.odg
    │   │   ├── assignment5q5.odg
    │   │   ├── assignment5q6.odg
    │   │   └── assignment5q7.odg
    │   ├── assignment6
    │   │   ├── List.c
    │   │   ├── List.h
    │   │   ├── Matrix1.txt
    │   │   ├── Matrix2.txt
    │   │   ├── MatrixDiff.txt
    │   │   ├── MatrixSum.txt
    │   │   ├── main
    │   │   ├── main.c
    │   │   ├── matrix1.txt
    │   │   ├── matrix2.txt
    │   │   ├── matrix3.txt
    │   │   └── matrix4.txt
    │   ├── assignment7
    │   │   ├── header.h
    │   │   ├── logic.c
    │   │   ├── main
    │   │   └── main.c
    │   └── assignment8
    │       ├── header.h
    │       ├── logic.c
    │       ├── main
    │       └── main.c
    ├── dsa2
    │   ├── assignment1
    │   │   ├── header.h
    │   │   ├── logic.c
    │   │   ├── main
    │   │   └── main.c
    │   ├── assignment2
    │   │   ├── header.h
    │   │   ├── logic.c
    │   │   ├── main
    │   │   ├── main.c
    │   │   ├── stack.c
    │   │   └── stack.h
    │   ├── assignment3
    │   │   ├── binaryTree.c
    │   │   ├── binaryTree.h
    │   │   ├── infixToExpressionTree.c
    │   │   ├── main
    │   │   ├── main.c
    │   │   ├── stack.c
    │   │   └── stack.h
    │   ├── assignment4
    │   │   ├── header.h
    │   │   ├── logic.c
    │   │   ├── main
    │   │   ├── main.c
    │   │   └── menu.c
    │   ├── assignment5
    │   │   ├── header.h
    │   │   ├── logic.c
    │   │   └── main.c
    │   ├── assignment6
    │   │   ├── graph.txt
    │   │   ├── header.h
    │   │   ├── logic.c
    │   │   ├── main
    │   │   └── main.c
    │   └── assignment7
    │       ├── graph.txt
    │       ├── header.h
    │       ├── logic.c
    │       ├── main
    │       ├── main.c
    │       ├── queue.c
    │       └── queue.h
    ├── infixToPostfix
    │   ├── characterStackUsingDLL.c
    │   ├── characterStackUsingDLL.h
    │   ├── logic.c
    │   ├── main
    │   └── main.c
    ├── labworks
    │   ├── arrayADT
    │   │   ├── header.h
    │   │   ├── logic.c
    │   │   ├── main
    │   │   └── main.c
    │   ├── doublyLinkedList
    │   │   ├── header.h
    │   │   ├── logic.c
    │   │   ├── main
    │   │   └── main.c
    │   ├── labwork1
    │   │   ├── q1.c
    │   │   ├── q2.c
    │   │   └── q3.c
    │   ├── labwork2
    │   │   └── main.c
    │   ├── labwork3
    │   │   └── main.c
    │   ├── labwork4
    │   │   ├── q1.c
    │   │   ├── q10.c
    │   │   ├── q11.c
    │   │   ├── q12.c
    │   │   ├── q13.c
    │   │   ├── q14.c
    │   │   ├── q15.c
    │   │   ├── q16.c
    │   │   ├── q2.c
    │   │   ├── q3.c
    │   │   ├── q4.c
    │   │   ├── q5.c
    │   │   ├── q6.c
    │   │   ├── q7.c
    │   │   ├── q8.c
    │   │   └── q9.c
    │   ├── labwork5
    │   │   ├── q1.c
    │   │   ├── q10.c
    │   │   ├── q11.c
    │   │   ├── q12.c
    │   │   ├── q13.c
    │   │   ├── q14.c
    │   │   ├── q15.c
    │   │   ├── q16.c
    │   │   ├── q17.c
    │   │   ├── q18.c
    │   │   ├── q19.c
    │   │   ├── q2.c
    │   │   ├── q20.c
    │   │   ├── q3.c
    │   │   ├── q4.c
    │   │   ├── q5.c
    │   │   ├── q6.c
    │   │   ├── q7.c
    │   │   ├── q8.c
    │   │   └── q9.c
    │   ├── labwork6
    │   │   ├── q1.c
    │   │   ├── q10.c
    │   │   ├── q11.c
    │   │   ├── q12.c
    │   │   ├── q13.c
    │   │   ├── q14.c
    │   │   ├── q15.c
    │   │   ├── q2.c
    │   │   ├── q3.c
    │   │   ├── q4.c
    │   │   ├── q5.c
    │   │   ├── q6.c
    │   │   ├── q7.c
    │   │   ├── q8.c
    │   │   └── q9.c
    │   ├── labwork7
    │   │   ├── q1.c
    │   │   ├── q10.c
    │   │   ├── q2.c
    │   │   ├── q3.c
    │   │   ├── q4.c
    │   │   ├── q5.c
    │   │   ├── q6.c
    │   │   ├── q7.c
    │   │   ├── q8.c
    │   │   └── q9.c
    │   ├── labwork8
    │   │   ├── q1+2.c
    │   │   ├── q3.c
    │   │   ├── q4.c
    │   │   ├── q5.c
    │   │   ├── q6.c
    │   │   └── q7.c
    │   ├── linkedListADT
    │   │   ├── header.h
    │   │   ├── logic.c
    │   │   ├── main
    │   │   └── main.c
    │   └── pointers
    │       ├── part2q1.c
    │       └── part2q2.c
    ├── linkedListADT
    │   ├── header.h
    │   ├── logic.c
    │   ├── main
    │   └── main.c
    ├── polynomialsLinkedList
    │   ├── header.h
    │   ├── logic.c
    │   ├── main
    │   └── main.c
    ├── queueUsingArray
    │   ├── header.h
    │   ├── logic.c
    │   ├── main
    │   └── main.c
    ├── queueUsingSLL
    │   ├── header.h
    │   ├── logic.c
    │   ├── main
    │   └── main.c
    ├── searchingAlgorithms
    │   └── linearSearch
    │       ├── arrayADT
    │       ├── arrayADT.c
    │       ├── linkedListADT
    │       └── linkedListADT.c
    ├── sortingAlgorithms
    │   ├── bubbleSort
    │   │   ├── arrayADT
    │   │   ├── arrayADT.c
    │   │   ├── bubbleSort.txt
    │   │   ├── linkedListADT
    │   │   └── linkedListADT.c
    │   ├── insertionSort
    │   │   ├── arrayADT
    │   │   ├── arrayADT.c
    │   │   ├── insertionSort.txt
    │   │   ├── linkedListADT
    │   │   └── linkedListADT.c
    │   ├── mergeSort
    │   │   ├── arrayADT
    │   │   ├── arrayADT.c
    │   │   ├── linkedListADT
    │   │   ├── linkedListADT.c
    │   │   └── mergeSort.txt
    │   └── selectionSort
    │       ├── arrayADT
    │       ├── arrayADT.c
    │       ├── linkedListADT
    │       ├── linkedListADT.c
    │       └── selectionSort.txt
    ├── stackUsingArray
    │   ├── header.h
    │   ├── logic.c
    │   ├── main
    │   └── main.c
    ├── stackUsingDLL
    │   ├── header.h
    │   ├── logic.c
    │   ├── main
    │   └── main.c
    └── stackUsingSLL
        ├── header.h
        ├── logic.c
        ├── main
        └── main.c
```

---

##  Getting Started

***Requirements***

###  Installation

1. Clone the DSA repository:

```sh
git clone https://github.com/prathampt/DSA
```

2. Change to the project directory:

```sh
cd DSA
```


##  Contributing

Contributions are welcome! Here are several ways you can contribute:

- **[Submit Pull Requests](https://github.com/prathampt/DSA/blob/main/CONTRIBUTING.md)**: Review open PRs, and submit your own PRs.
- **[Join the Discussions](https://github.com/prathampt/DSA/discussions)**: Share your insights, provide feedback, or ask questions.
- **[Report Issues](https://github.com/prathampt/DSA/issues)**: Submit bugs found or log feature requests for Dsa.

<details closed>
    <summary>Contributing Guidelines</summary>

1. **Fork the Repository**: Start by forking the project repository to your GitHub account.
2. **Clone Locally**: Clone the forked repository to your local machine using a Git client.
   ```sh
   git clone https://github.com/prathampt/DSA
   ```
3. **Create a New Branch**: Always work on a new branch, giving it a descriptive name.
   ```sh
   git checkout -b new-feature-x
   ```
4. **Make Your Changes**: Develop and test your changes locally.
5. **Commit Your Changes**: Commit with a clear message describing your updates.
   ```sh
   git commit -m 'Implemented new feature x.'
   ```
6. **Push to GitHub**: Push the changes to your forked repository.
   ```sh
   git push origin new-feature-x
   ```
7. **Submit a Pull Request**: Create a PR against the original project repository. Clearly describe the changes and their motivations.

Once your PR is reviewed and approved, it will be merged into the main branch.

</details>

