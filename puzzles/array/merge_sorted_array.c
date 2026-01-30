// problem -> https://leetcode.com/problems/merge-sorted-array/

// time complexity  -> O(M + N)
// space complexity -> O(M)

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
  // create a copy of nums1 array
  int *nums1cp = (int *)calloc(m, sizeof(int));
  if (!nums1cp) return;

  for (int i = 0; i < m; i++) nums1cp[i] = nums1[i];

  // pointer i & j to naviage the nums1cp & nums2 array
  // pointer u is for updating nums1 array with union
  int i = 0, j = 0, u = 0;
  while (i < m && j < n) {
    if (nums2[j] == nums1cp[i]) {
      nums1[u++] = nums2[j++];
      nums1[u++] = nums1cp[i++];
    }
    else if (nums1cp[i] < nums2[j])
      nums1[u++] = nums1cp[i++];
    else if (nums2[j] < nums1cp[i])
      nums1[u++] = nums2[j++];
  }

  // if any leftovers, then move it
  while (j < n) {
    nums1[u++] = nums2[j++];
  }
  while (i < m) {
    nums1[u++] = nums1cp[i++];
  }

  free(nums1cp);
}