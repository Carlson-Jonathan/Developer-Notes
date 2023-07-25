<h1>C++ Unit Testing</h1>
<p>This is a brief tutorial with examples of unit testing. There are three kinds of
C++ unit test methods here- one using only vanilla C++ code another using 
Google Test, and a third using UnitTest++. In any of the respective folders, 
compile the unit tests using CMake and run the Main.out file:</p>
<ol>
    <li>mkdir build</li>
    <li>cd build</li>
    <li>cmake ..</li>
    <li>make</li>
</ol>

<h2>A unit test...</h2>
<ul>
    <li>is a function that tests another function.</li>
    <li>tests functions at their lowest level.</li>
    <li>promotes clean coding practices.</li>
    <li>helps identify bugs early on.</li>
    <li>helps us plan code before we write it.</li>
</ul>

<h2>Good unit tests...</h2>
<ul>
    <li>test one thing at a time.</li>
    <li>tell exactly what test case broke and how.</li>
    <li>takes no input and returns a boolean.</li>
    <li>are stand-alone (no reliance on other tests).</li>
    <li>are up-to-date with the source code.</li>
    <li>work the same 100% of the time.</li>
    <li>cover all edge cases and extreme inputs.</li>
    <li>are simple and easy to read.</li>
</ul>

<h2>Un-testable (unit testable) functions...</h2>
<ul>
    <li>are excessivly long.</li>
    <li>do multiple things.</li>
    <li>return nothing (logs/pass-by-reference/etc).</li>
    <li>are high-level.</li>
</ul>

---------------------------------------------------------------

<h1>Unit Test Tool Installations</h1> 
<ol>
<li>Clone the repository</li>
    <ul>
        <li>https://github.com/google/googletest</li>
        <li>https://github.com/unittest-cpp/unittest-cpp</li>
    </ul>
<li>cd into the repository and build</li>
    <ol>
    <li>mkdir build</li>
    <li>cd build</li>
    <li>cmake ..</li>
    <li>make</li>
    <li>sudo make --install</li>
    </ol>
</ol>
