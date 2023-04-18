# Strictly Increasing Array
## Hard
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given an array <strong>nums[]</strong>&nbsp;of <strong>N</strong> positive integers. Find the minimum number of operations required to modify the&nbsp;array such&nbsp;that array elements are in&nbsp;strictly increasing order (A[i] &lt; A[i+1]).<br>
Changing&nbsp;a number to greater or lesser than original number is counted as one operation.</span></p>

<p><br>
<span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: </strong>nums[] = [1, 2, 3, 6, 5, 4]
<strong>Output: </strong>2
<strong>Explanation: </strong>By decreasing 6 by 2 and
increasing 4 by 2, arr will be like
[1, 2, 3, 4, 5, 6] which is stricly </span>
<span style="font-size:18px">increasing.</span>
</pre>

<p><br>
<span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>&nbsp;nums[] = [1, 2, 3, 4]
<strong>Output: </strong>0</span>
<span style="font-size:18px"><strong>Explanation: </strong>Arrays is already strictly
increasing.</span>
</pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read or print anything. Your task is to complete the function&nbsp;<strong>min_opeartions()&nbsp;</strong>which takes the array <strong>nums[] </strong>as input parameter and returns the minimum number of opeartion needed to make the array strictly increasing.</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(n^2)</span><br>
<span style="font-size:18px"><strong>Expected Space Complexity:&nbsp;</strong>O(n)</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:&nbsp;</strong><br>
1 &lt;= length of array &lt;= 1000<br>
1 &lt;= arr[i] &lt;= 1000000</span></p>
</div>